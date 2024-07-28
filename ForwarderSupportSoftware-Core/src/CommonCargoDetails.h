#ifndef COMMONCARGODETAILS_H
#define COMMONCARGODETAILS_H

#include <vector>

#include "types_and_defs.h"

// TODO(Make commodity much usefull)
namespace ForwarderSupportWare
{
	class CargoDetails
	{
		public:
			//const std::string& getCommodity() const;
			const int GetPieces() const;
			const float GetWeightKG() const ;
			const std::vector<Vec3> GetDimensions() const;

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
			std::vector<Vec3> m_Dimensions;
	};
}

#endif // COMMONCARGODETAILS_H