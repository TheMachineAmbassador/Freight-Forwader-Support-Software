/* Copyright (C) TMA Software - All Rights Reserved 2021-2023
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 * Written by Can Albayrak <karus54321@gmail.com>
 */

#ifndef AIRCARGOBASE_H
#define AIRCARGOBASE_H

#include "CommonCargoDetails.h"

namespace ForwarderSupportWare
{
	class AirCargoBase : public CargoDetails
	{
	private:
		float chargableWeight = 0;
		float chargableWeightHolder = 0;
	public:
		float getVolumeWeight() const;
	
		float getChargableWeight() const;

		void volumeWeightCalc();
		void setVolumeWeight(float volumeWeight);
		
		void calcSpecific() override
		{
			volumeWeightCalc();
		}
		void Clear() override
		{
			clearOzellikler();
			setVolumeWeight(0);
			setWeightKG(0);
		}
	};
}

#endif