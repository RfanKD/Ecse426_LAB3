/**
  ******************************************************************************
  * @file    	moving_avg.c
  * @author  	Group 5
  * @version 	V1.0.0
  * @date    	11-FEB-2014
  * @brief   	This file provides firmware functions to calculate the moving average
							of a buffer.
	* @misc{ 		This program appears in:
							"Programming Challenges: The Programming Contest Training Manual"
							by Steven Skiena and Miguel Revilla, Springer-Verlag, New York 2003.
							source = https://www.cs.sunysb.edu/~skiena/392/programs/queue.c
							author = "Steven Skiena",
							title = "queue.c",
							date = "March 27, 2002" }
  ******************************************************************************/
	
/* Includes ------------------------------------------------------------------------*/
#include "moving_avg.h"
#include "stdio.h"

/**
  * @brief  Initializes the buffer. This buffer is essencially implemented as a Queue
  * @param  Queue pointer: pointer to queue structure 
  * @retval None
  */
void init_queue(queue *q)
{
	/* Initialize the queue*/
	q->first = 0;
  q->last = QUEUESIZE - 1;
	q->count = 0;
	q->sum = 0;
}

/**
  * @brief  Moving out the first data inside a queue in a FIFO fashion 
  * @param  Queue pointer
  * @retval None
  */
void dequeue(queue *q)
{
	/* Moving the second data to the first position*/
	q->first = (q->first+1) % QUEUESIZE;
	
	/* Calculate the moving average*/
	q->avg = q->sum / QUEUESIZE;
	
	/* Decrease the sum by the kicked out data */
	q->sum -= q->q[q->first];
	
	/* Making a spot for the next data by decrementing the counter*/
	q->count = q->count - 1;
	
	/* print out the moving average and the sum*/
	//printf("\ntest---dequeue start --- AVG = %d\n",q->avg);
}


/**
  * @brief  Moving in a data if only if the queue is not full
  * @param  QUEUE pointer
						int: data 
  * @retval None
  */
void enqueue(queue *q, int x)
{
				/* Check if the queue is full*/
        if (q->count == QUEUESIZE)
				
					/* If it is full, go to dequeue */
					dequeue(q);
        else {
					
					/* Starting to enqueue */
					/* 1. Updating the last position*/
					q->last = (q->last+1) % QUEUESIZE;
					
					/* 2. Moving in the data*/
          q->q[q->last] = x;    
					
					/* 3. Incrementing the counter */
          q->count = q->count + 1;
					
					/* 4. Print its position, the entered value, the counter*/
					//printf("enqueue q[%d] %d %d",q->last,q->q[q->last],q->count);
					
					/* 5. Incrementing the sum*/
					q->sum += x;
				}
}
/**
  * @}
  */ 


