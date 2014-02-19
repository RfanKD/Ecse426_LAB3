/**
  ******************************************************************************
  * @file    moving_avg.h
  * @author  Group 5
  * @version V1.0.0
  * @date    11-FEB-2014
  * @brief   This file contains all the functions prototypes  
						 to configure moving average
  ******************************************************************************/
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MOVING_AVG_H
#define __MOVING_AVG_H
#define QUEUESIZE 20
typedef struct {
	int q[QUEUESIZE];
	int first;
	int last;
	int count;
	int sum;
	int avg;
}queue;
void init_queue(queue *q);
void dequeue(queue *q);
void enqueue(queue *q, int x);
#endif
/**
  * @}
  */ 
