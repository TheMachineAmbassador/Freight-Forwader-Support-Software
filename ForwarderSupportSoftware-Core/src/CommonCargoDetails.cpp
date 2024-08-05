#include "CommonCargoDetails.h"

#include <map>


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

const std::vector<PalletPacking>& CargoDetails::GetDimensions() const
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

void CargoDetails::PushValueToDimensions(Vec3 stuff, int adet, bool stackable)
{
    m_Dimensions.push_back({ adet, stackable, stuff });

    // Maps to aggregate counts by dimensions, separating stackable and non-stackable items
    std::map<Vec3, DimensionInfo, Vec3Compare> stackableMap;
    std::map<Vec3, DimensionInfo, Vec3Compare> nonStackableMap;

    // Traverse the vector and update counts in the appropriate map
    for (const auto& item : m_Dimensions) {
        if (item.IsStackable) {
            auto& dimInfo = stackableMap[item.Dimension];
            dimInfo.Count += item.Count;
            dimInfo.Stackable = true; // All items in this map are stackable
        }
        else {
            auto& dimInfo = nonStackableMap[item.Dimension];
            dimInfo.Count += item.Count;
            dimInfo.Stackable = false; // All items in this map are non-stackable
        }
    }

    // Clear the original vector
    m_Dimensions.clear();

    // Rebuild the vector with updated counts for stackable items
    for (const auto& [dimensions, dimInfo] : stackableMap) {
        m_Dimensions.push_back({ dimInfo.Count, true, dimensions });
    }

    // Rebuild the vector with updated counts for non-stackable items
    for (const auto& [dimensions, dimInfo] : nonStackableMap) {
        m_Dimensions.push_back({ dimInfo.Count, false, dimensions });
    }

    OnCalculate();
}


void CargoDetails::ClearDimensions()
{
	m_Dimensions.clear();
}
