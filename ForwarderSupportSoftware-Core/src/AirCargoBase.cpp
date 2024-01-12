#include "AirCargoBase.h"

namespace ForwarderSupportWare
{
    float AirCargoBase::getVolumeWeight() const
    {
        return this->chargableWeight;
    }

    void AirCargoBase::setVolumeWeight(float volumeWeight)
    {
        this->chargableWeight = volumeWeight;
    }

    void AirCargoBase::volumeWeightCalc()
    {
        float collector = 0;

        for (auto& i : getOzelliker())
        {
            collector = collector + ((i.x * i.y * i.z) / 6000);
        }
        setVolumeWeight(collector);
    }

    float AirCargoBase::getChargableWeight() const
    {
        float chargableWeightHolder = 0;
        if (getWeightKG() <= getVolumeWeight())
        {
            return getVolumeWeight();
        }
        else
        {
            return getWeightKG();
        }
    }
}