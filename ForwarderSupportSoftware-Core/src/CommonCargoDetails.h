#ifndef COMMONCARGODETAILS_H
#define COMMONCARGODETAILS_H

#include <vector>

#include "types_and_defs.h"

namespace ForwarderSupportWare
{
	enum CargoType
	{
		Sea = 0, Air, Land, MAX
	};

	enum e_Packing
	{
		Pallet, Drum, Max
	};

	struct PalletPackingDefine
	{
		int Count;
		Vec3 Dimension;
	};

	struct DrumPackingDefine
	{
		int Count;
		Vec2 Dimension;
	};

	class CargoDetails
	{
		public:
			static e_Packing type;

			// TODO(Make commodity usefull)
			//const std::string& getCommodity() const;

			const int GetPieces() const;
			const float GetWeightKG() const ;
			const std::vector<PalletPackingDefine>& GetDimensions() const;

			//void setCommodity(std::string Commodity);
			void SetWeightKG(float weightKG);
		
			void PushValueToDimensions(Vec3 Stuff, int adet);
			void ClearDimensions();

			virtual void OnCalculate() {};
			virtual void Clear() {};

		private:
			//std::string Commodity = "";
			int m_Pieces = 0;
			int m_SumOfPieces = 0;
			float m_WeightKG = 0;
			std::vector<PalletPackingDefine> m_Dimensions;
	};
}

#endif // COMMONCARGODETAILS_H