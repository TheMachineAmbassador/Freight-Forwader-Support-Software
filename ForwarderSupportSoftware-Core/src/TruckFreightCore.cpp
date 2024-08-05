#include "TruckFreightCore.h"


float TruckFreightCore::getLDM() const
{
    return this->ldm;
}

void TruckFreightCore::setLDM(float ldmParam)
{
    this->ldm = ldmParam;
}

float TruckFreightCore::calculateLdm() const
{
    float collector = 0;

    for (auto& i : GetDimensions())
    {
        if (i.IsStackable == false)
            collector = collector + ( i.Count * (((i.Dimension.x * i.Dimension.y) / 2.4f / 10000) / 2));
        else
            collector = collector + ( i.Count * ((i.Dimension.x * i.Dimension.y) / 2.4f / 10000));
    }
    return collector;
}
