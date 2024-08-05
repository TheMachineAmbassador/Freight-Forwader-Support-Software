#ifndef CUSTOMMATH_H
#define CUSTOMMATH_H

constexpr float HMF_RATE = 0.00125f;
constexpr float MPF_RATE = 0.003464f;
constexpr float MPF_MIN = 25.0f;


const float calcMPFValue(const float& TotalCustomValue);
float calcHMFValue(const float& TotalCustomValue);

#endif // CUSTOMMATH_H