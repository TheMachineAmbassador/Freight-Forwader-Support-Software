#include "TruckFreightCore.h"

float TruckFreightCore::getLDM() const
{
    return this->ldm;
}

void TruckFreightCore::setLDM(float ldmParam)
{
    this->ldm = ldmParam;
}

float TruckFreightCore::calculateLdm(const bool& isStackable) const
{
    float collector = 0;

    for (auto& i : getOzelliker())
    {
        if (isStackable == false)
            collector = collector + (((i.x * i.y) / 2.4f / 10000) / 2);
        else
            collector = collector + ((i.x * i.y) / 2.4f / 10000);
    }
    return collector;
}