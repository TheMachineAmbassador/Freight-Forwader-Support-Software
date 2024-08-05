/* Copyright (C) TMA Software - All Rights Reserved 2021-2023
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 * Written by Can Albayrak <karus54321@gmail.com>
 */

#ifndef AIRCARGOBASE_H
#define AIRCARGOBASE_H

#include "CommonCargoDetails.h"

class AirCargoBase : public CargoDetails
{
	public:
		float getVolumeWeight() const;
	
		float getChargableWeight() const;

		void volumeWeightCalc();
		void setVolumeWeight(float volumeWeight);
		
		void OnCalculate() override
		{
			volumeWeightCalc();
		}
		void Clear() override
		{
			ClearDimensions();
			setVolumeWeight(0);
			SetWeightKG(0);
		}
	private:
		float m_ChargableWeight = 0;
		float m_ChargableWeightHolder = 0;
};


#endif