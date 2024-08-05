#ifndef COMMONCARGODETAILS_H
#define COMMONCARGODETAILS_H

#include <vector>

#include "types_and_defs.h"

enum class CargoType : int8_t
{
	Sea = 0,
	Air,
	Land,
	MaxTypes
};

enum class PackingType : int8_t
{
	Pallet,
	Drum,
	MaxPackingTypes
};

struct PalletPacking
{
	int Count;
	bool IsStackable;
	Vec3 Dimension;
};

struct DrumPacking
{
	int Count;
	Vec2 Dimension;
};


class CargoDetails
{
	public:
		struct DimensionInfo {
			int Count;
			bool Stackable;
		};

		static inline CargoType type;

		// TODO(Make commodity usefull)
		//const std::string& getCommodity() const;

		const int GetPieces() const;
		const float GetWeightKG() const ;
		const std::vector<PalletPacking>& GetDimensions() const;

		//void setCommodity(std::string Commodity);
		void SetWeightKG(float weightKG);

		void PushValueToDimensions(Vec3 Stuff, int adet,bool stackable);
		void ClearDimensions();

		virtual void OnCalculate() {};
		virtual void Clear() {};

	private:
		//std::string Commodity = "";
		int m_Pieces = 0;
		int m_SumOfPieces = 0;
		float m_WeightKG = 0;
		float m_Tonnage = 0;

		std::vector<PalletPacking> m_Dimensions;
};


#endif // COMMONCARGODETAILS_H