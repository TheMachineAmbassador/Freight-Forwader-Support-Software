#ifndef COMMONCARGODETAILS_H
#define COMMONCARGODETAILS_H

#include <vector>

#include "types_and_defs.h"

// TODO(Make commodity much usefull)
namespace ForwarderSupportWare
{
	class CargoDetails
	{
		private:
			//std::string Commodity = "";
			int pieces = 0;
			int sumPieces = 0;
			float weightKG = 0;
			std::vector<Vec3> Ozellikler;

		protected:
		
		public:
			//const std::string& getCommodity() const;
			const int getPieces() const;
			const float getWeightKG() const ;
			const std::vector<Vec3> getOzelliker() const;

			//void setCommodity(std::string Commodity);
			void setWeightKG(float weightKG);
		
			void pushValueToOzelliker(Vec3 Stuff, int adet);

			virtual void calcSpecific() {};
			virtual void Clear() {};

			void clearOzellikler();
	};
}

#endif // COMMONCARGODETAILS_H