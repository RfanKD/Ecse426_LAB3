#include <stdio.h>
#include "stm32f4xx.h"
#include "stm32f4xx_conf.h"
#include "math.h"
#include "atan_LUT.h"
#include "accelerometer.h"
#include "moving_avg.h"
#include "lis3dsh.h"
//#include "stm32f4_discovery_lis302dl.h"

#define PRECISION 10
float* acc_raw;
int acc_x, acc_y, acc_z;
queue axis_x;
queue axis_y;
queue axis_z;

int main()
{
	accelerometer_init();
	init_queue(&axis_x);
	
	while (1){
		//accelerometer raw data type float with precision 0.000001
		acc_raw = getAccelerometerData();
		printf("%.3f\n",*(acc_raw));
		printf("%.3f\n",*(acc_raw+1));
		printf("%.3f\n",*(acc_raw+2));
		//printf("%f	%f	%f\n",*acc_raw,*(acc_raw+1), *(acc_raw+2));
		
////		//accelerometer raw data type int with precision 0.1
////		acc_x = *acc_raw * PRECISION;
////		acc_y = *(acc_raw+1) * PRECISION;
////		acc_z = *(acc_raw+2) * PRECISION;
////		//printf("raw:%d  %d  %d ",acc_x,acc_y, acc_z);

////		enqueue(&axis_x, acc_x);
//// 	  enqueue(&axis_y, acc_y);
////		enqueue(&axis_z, acc_z);
////		//printf(" avg:<%d  %d %d>\n",axis_x.avg, axis_y.avg, axis_z.avg);
	}
}







