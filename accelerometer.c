#include "lis3dsh.h"
#include "accelerometer.h"
#include "moving_avg.h"


float accelerometer_raw [3];

void accelerometer_init(){
	LIS3DSH_InitTypeDef init_accelerometer;
	
	init_accelerometer.Power_Mode_Output_DataRate = LIS3DSH_DATARATE_100;
	init_accelerometer.Axes_Enable = LIS3DSH_X_ENABLE|LIS3DSH_Y_ENABLE|LIS3DSH_Z_ENABLE;
	init_accelerometer.Continous_Update = LIS3DSH_ContinousUpdate_Disabled;
	init_accelerometer.AA_Filter_BW = LIS3DSH_AA_BW_800;
	init_accelerometer.Full_Scale = LIS3DSH_FULLSCALE_2;
	init_accelerometer.Self_Test = LIS3DSH_SELFTEST_NORMAL;
	
	LIS3DSH_Init(&init_accelerometer);
	
}

float* getAccelerometerData(){
	float out[3];
	LIS3DSH_ReadACC(out);
	accelerometer_raw[0] = out[0];
	
	accelerometer_raw[1] = out[1];

	
	accelerometer_raw[2] = out[2];

	return (&accelerometer_raw[0]);
}
