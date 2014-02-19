#ifndef __ACCELEROMETER_H
#define __ACCELEROMETER_H


void accelerometer_init(void);
float* getAccelerometerData(void);
float get_avg_x(float);
float get_avg_y(float);
float get_avg_z(float);
#endif
