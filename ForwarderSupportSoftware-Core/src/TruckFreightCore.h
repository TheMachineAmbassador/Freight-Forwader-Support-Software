#ifndef TRUCKFREIGHTCORE_H
#define TRUCKFREIGHTCORE_H

#include "CommonCargoDetails.h"

namespace ForwarderSupportWare
{
	class TruckFreightCore : public CargoDetails
	{
	public:
		float getLDM() const;

		void OnCalculate() override
		{
			setLDM(calculateLdm(isStackable));
		}
		void Clear() override
		{
			ClearDimensions();
			setLDM(0);
			SetWeightKG(0);
		}

		void setLDM(float volumeWeight);
		float calculateLdm(const bool& isStackable) const;
	public:
		bool isStackable = false;

	private:
		float ldm = 0;
	};
}
#endif