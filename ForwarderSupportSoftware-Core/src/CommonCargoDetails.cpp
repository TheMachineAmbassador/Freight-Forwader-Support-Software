#include "CommonCargoDetails.h"

namespace ForwarderSupportWare
{
	/*const std::string& CargoDetails::getCommodity() const
	{
		return this->Commodity;
	}*/

	const int CargoDetails::GetPieces() const
	{
		return static_cast<int>(this->m_Dimensions.size());
	}

	const float CargoDetails::GetWeightKG() const 
	{
		return this->m_WeightKG;
	}

	const std::vector<Vec3> CargoDetails::GetDimensions() const
	{
		return this->m_Dimensions;
	}

	//void CargoDetails::setCommodity(std::string Commodity)
	//{
	//	this->Commodity = Commodity;
	//}

	void CargoDetails::SetWeightKG(float weightKG)
	{
		this->m_WeightKG = weightKG;
	}

	void CargoDetails::PushValueToDimensions(Vec3 stuff, int adet)
	{
		for (int i = 0; i < adet; i++)
		{
			m_Dimensions.push_back(stuff);
		}
		OnCalculate();
	}

	void CargoDetails::ClearDimensions()
	{
		m_Dimensions.clear();
	}
}
