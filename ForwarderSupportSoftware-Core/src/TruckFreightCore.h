#ifndef TRUCKFREIGHTCORE_H
#define TRUCKFREIGHTCORE_H

#include "CommonCargoDetails.h"
#include "types_and_defs.h"

class TruckFreightCore : public ForwarderSupportWare::CargoDetails
{
private:
	float ldm = 0;

	bool isStackable = false;

public:

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