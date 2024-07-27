#ifndef TRUCKFREIGHTCORE_H
#define TRUCKFREIGHTCORE_H

#include "CommonCargoDetails.h"

class TruckFreightCore : public ForwarderSupportWare::CargoDetails
{
private:
	float ldm = 0;


public:
	bool isStackable = false;

	float getLDM() const;

	void calcSpecific() override
	{
		setLDM(calculateLdm(isStackable));
	}
	void Clear() override
	{
		clearOzellikler();
		setLDM(0);
		setWeightKG(0);
	}

	void setLDM(float volumeWeight);
	float calculateLdm(const bool& isStackable) const;
};

#endif