#ifndef SEACARGOBASE_H
#define SEACARGOBASE_H

#include "CommonCargoDetails.h"
#include "types_and_defs.h"

namespace ForwarderSupportWare
{
	class SeaCargoBase : public CargoDetails
	{
	private:
		float volumeCBM = 0;
		float volumeCBF = 0;
		float weightLbs = 0;
		float wmValue = 0;

	public:
		float getVolume() const;

		void setVolumeCBM(float volumeCBM);
		float SeaCBMCalc() const;

		double getVolumeCBF() const;
		void setVolumeCBF(float volumeCBF);

		double getWeightLbs() const;
		void setWeightLBS(float weightLbs);

		float getWMValue();
		
		void calcSpecific() override
		{
			setVolumeCBM(SeaCBMCalc());
			setVolumeCBF(SeaCBMCalc());
		}

		void Clear() override
		{
			clearOzellikler();
			setVolumeCBM(0);
			setVolumeCBF(0);
			SeaCBMCalc();
			setWeightKG(0);
			setWeightLBS(0);
		}
	};
}
#endif
