#ifndef CUSTOMMATH_H
#define CUSTOMMATH_H

#define HMF_RATE	0.00125f
#define MPF_RATE	0.003464f
#define MPF_MIN		25.0f


const float calcMPFValue(const float& TotalCustomValue);
float calcHMFValue(const float& TotalCustomValue);

#endif