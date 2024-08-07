#include "AirCargoBase.h"

float AirCargoBase::getVolumeWeight() const
{
    return this->m_ChargableWeight;
}

void AirCargoBase::setVolumeWeight(float volumeWeight)
{
    this->m_ChargableWeight = volumeWeight;
}

void AirCargoBase::volumeWeightCalc()
{
    float collector = 0;

    for (auto& i : GetDimensions())
    {
        collector = collector + ( i.Count * ((i.Dimension.x * i.Dimension.y * i.Dimension.z) / 6000));
    }
    setVolumeWeight(collector);
}

float AirCargoBase::getChargableWeight() const
{
    float chargableWeightHolder = 0;
    if (GetWeightKG() <= getVolumeWeight())
    {
        return getVolumeWeight();
    }
    else
    {
        return GetWeightKG();
    }
}