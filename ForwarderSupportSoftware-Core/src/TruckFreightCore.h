#ifndef TRUCKFREIGHTCORE_H
#define TRUCKFREIGHTCORE_H

#include "CommonCargoDetails.h"

class TruckFreightCore : public CargoDetails
{
public:
	float getLDM() const;

	void OnCalculate() override
	{
		setLDM(calculateLdm());
	}
	void Clear() override
	{
		ClearDimensions();
		setLDM(0);
		SetWeightKG(0);
	}

	void setLDM(float volumeWeight);
	float calculateLdm() const;

private:
	float ldm = 0;
};

#endif