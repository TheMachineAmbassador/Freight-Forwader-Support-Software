#include "SeaCargoBase.h"

namespace ForwarderSupportWare
{
	float SeaCargoBase::getVolume() const
	{
		return this->volumeCBM;
	}

	void SeaCargoBase::setVolumeCBM(float volumeCBM)
	{
		this->volumeCBM = volumeCBM;
	}

    float SeaCargoBase::getWMValue()
    {
        const float tonnage = getWeightKG() / 1000.0f;
        wmValue = tonnage <= getVolume() ? getVolume() : tonnage;
        return this->wmValue;
    }

	float SeaCargoBase::SeaCBMCalc() const
	{
		float collector = 0;

		for (auto& i : getOzelliker())
		{
			collector = collector + (i.x * i.y * i.z);
		}

		return collector;
	}

	double SeaCargoBase::getVolumeCBF() const
	{
		return this->volumeCBF;
	}

	void SeaCargoBase::setVolumeCBF(float volumeCBF)
	{
		this->volumeCBF = volumeCBF * 35.3147f;
	}

	void SeaCargoBase::setWeightLBS(float weightLBS)
	{
		this->weightLbs = weightLBS * 2.204622622f;
	}

	double SeaCargoBase::getWeightLbs() const
	{
		return this->weightLbs;
	}

#if 0
    void SeaCargoBase::renderDenizNavlun()
    {
        const float weightBuff = getWeightKG();
        const float tonnage = getWeightKG() / 1000.0f;
        this->wmValue = tonnage <= getVolume() ? getVolume() : tonnage;

        output =  std::format("Pieces: {}\n", std::to_string(getPieces()));
        output += std::format("Weight: {0:.3f} KG / {1:.3f} Ton\n", weightBuff, tonnage);
        output += std::format("Volume: (CBM): {0:.3f}\n", getVolume());
        output += std::format("Weight: (LBS/Pound): {0:.3f} LBS\n", getWeightLbs());
        output += std::format("Volume: (CBF): {0:.3f}\n", getVolumeCBF());
        output += std::format("W/M: {0:.3f}", this->wmValue);

        ImGui::Text(output.c_str());

        ImGui::Separator();

        ImGui::PushItemWidth(120);
        ImGui::Text("Adet:                      "); ImGui::SameLine(); ImGui::InputScalar("##Adet", ImGuiDataType_U32, &Adet);

        ImGui::Text("Uzunluk:                "); ImGui::SameLine(); ImGui::InputFloat("##Length", &length, 0.0f, 0.0f, "%.4f", ImGuiInputTextFlags_CharsScientific);
        ImGui::SameLine();
        displayUnitRadioButtons("length_unit", &length_unit);

        ImGui::Text("Geniþlik:                "); ImGui::SameLine(); ImGui::InputFloat("##Width", &width, 0.0f, 0.0f, "%.4f", ImGuiInputTextFlags_CharsScientific);
        ImGui::SameLine();
        displayUnitRadioButtons("width_unit", &width_unit);

        ImGui::Text("Yükseklik:              "); ImGui::SameLine(); ImGui::InputFloat("##Height", &height, 0.0f, 0.0f, "%.4f", ImGuiInputTextFlags_CharsScientific);
        ImGui::SameLine();
        displayUnitRadioButtons("height_unit", &height_unit);
        
        ImGui::Text("Input the Weight: "); ImGui::SameLine();
        if (ImGui::InputFloat("##WeightKGs", &weightKGHolder))
        {
            setWeightKG(weightKGHolder);
            setWeightLBS(getWeightKG());
        }
        ImGui::PopItemWidth();

        ImGui::Separator();

        if (ImGui::Button("Ekle", { 120,0 }))
        {
            Vec3 stuff{};

            stuff.x = convertToMeters(length, length_unit);
            stuff.y = convertToMeters(width, width_unit);
            stuff.z = convertToMeters(height, height_unit);
            pushValueToOzelliker(stuff,Adet);
            
            const float cbmHolder = SeaCBMCalc();

            setVolumeCBM(cbmHolder);
            setVolumeCBF(cbmHolder);
        }

        ImGui::SameLine();
        if (ImGui::Button("Reset/Temizle", { 120,0 }))
        {
            clearOzellikler();
            setVolumeCBM(0);
            setVolumeCBF(0);
            SeaCBMCalc();
            wmValue = 0;
            setWeightKG(0);
            setWeightLBS(0);
        }

        ImGui::SameLine();
        if (ImGui::Button("Verileri Kopyala", { 120,0 }))
        {
            CopyClipboard(output);
        }
    }
#endif
}