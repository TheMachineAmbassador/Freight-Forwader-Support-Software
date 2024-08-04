#include "SeaCargoBase.h"

namespace ForwarderSupportWare
{
	float SeaCargoBase::getVolume() const
	{
		return this->volumeCBM;
	}

	void SeaCargoBase::setVolumeCBM(float volumeCBM)
	{
		this->volumeCBM = volumeCBM;
	}

    float SeaCargoBase::getWMValue()
    {
        const float tonnage = GetWeightKG() / 1000.0f;
        wmValue = tonnage <= getVolume() ? getVolume() : tonnage;
        return this->wmValue;
    }

	float SeaCargoBase::SeaCBMCalc() const
	{
		float collector = 0;

		for (auto& i : GetDimensions())
		{
			collector = collector + ( i.Count * (i.Dimension.x * i.Dimension.y * i.Dimension.z));
		}

		return collector;
	}

	double SeaCargoBase::getVolumeCBF() const
	{
		return this->volumeCBF;
	}

	void SeaCargoBase::setVolumeCBF(float volumeCBF)
	{
		this->volumeCBF = volumeCBF * 35.3147f;
	}

	void SeaCargoBase::setWeightLBS(float weightLBS)
	{
		this->weightLbs = weightLBS * 2.204622622f;
	}

	double SeaCargoBase::getWeightLbs() const
	{
		return this->weightLbs;
	}
}