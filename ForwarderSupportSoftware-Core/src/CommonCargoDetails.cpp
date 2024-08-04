#include "CommonCargoDetails.h"

#include <map>


namespace ForwarderSupportWare
{
	/*const std::string& CargoDetails::getCommodity() const
	{
		return this->Commodity;
	}*/

	const int CargoDetails::GetPieces() const
	{
		int counter = 0;
		for (auto& i : m_Dimensions)
		{
			counter += i.Count;
		}
		return counter;
	}

	const float CargoDetails::GetWeightKG() const 
	{
		return this->m_WeightKG;
	}

	const std::vector<PalletPackingDefine>& CargoDetails::GetDimensions() const
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
	static bool firstTime = false;

	void CargoDetails::PushValueToDimensions(Vec3 stuff, int adet)
	{
		m_Dimensions.push_back({ adet,stuff });

		// Use a map to aggregate counts by dimensions
		std::map<Vec3, int, Vec3Compare> dimensionCountMap;

		// Traverse the vector and update counts in the map
		for (const auto& item : m_Dimensions) {
			dimensionCountMap[item.Dimension] += item.Count;
		}

		// Clear the original vector
		m_Dimensions.clear();

		// Rebuild the vector with updated counts
		for (const auto& [dimensions, count] : dimensionCountMap) {
			m_Dimensions.push_back({ count, dimensions });
		}

		OnCalculate();
	}

	void CargoDetails::ClearDimensions()
	{
		m_Dimensions.clear();
	}
}
