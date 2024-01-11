#include "CommonCargoDetails.h"

namespace ForwarderSupportWare
{
	/*const std::string& CargoDetails::getCommodity() const
	{
		return this->Commodity;
	}*/

	const int CargoDetails::getPieces() const
	{
		return static_cast<int>(this->Ozellikler.size());
	}

	const float CargoDetails::getWeightKG() const 
	{
		return this->weightKG;
	}

	const std::vector<Vec3> CargoDetails::getOzelliker() const
	{
		return this->Ozellikler;
	}

	//void CargoDetails::setCommodity(std::string Commodity)
	//{
	//	this->Commodity = Commodity;
	//}

	void CargoDetails::setWeightKG(float weightKG)
	{
		this->weightKG = weightKG;
	}

	void CargoDetails::pushValueToOzelliker(Vec3 stuff, int adet)
	{
		for (int i = 0; i < adet; i++)
		{
			Ozellikler.push_back(stuff);
		}
		calcSpecific();
	}

	void CargoDetails::clearOzellikler()
	{
		Ozellikler.clear();
	}
}
