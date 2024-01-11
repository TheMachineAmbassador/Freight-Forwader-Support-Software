#include "CustomMath.h"

const float calcMPFValue(const float& TotalCustomValue)
{
    // Calculate MPF
    float mpf = TotalCustomValue * MPF_RATE;
    if (mpf < MPF_MIN) {
        mpf = MPF_MIN;
    }
    return mpf;
}

float calcHMFValue(const float& TotalCustomValue)
{
    return TotalCustomValue * HMF_RATE;
}