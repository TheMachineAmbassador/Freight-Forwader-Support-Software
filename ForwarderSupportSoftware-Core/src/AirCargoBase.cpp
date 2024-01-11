#include "AirCargoBase.h"

namespace ForwarderSupportWare
{
    float AirCargoBase::getVolumeWeight() const
    {
        return this->chargableWeight;
    }

    void AirCargoBase::setVolumeWeight(float volumeWeight)
    {
        this->chargableWeight = volumeWeight;
    }

    void AirCargoBase::volumeWeightCalc()
    {
        float collector = 0;

        for (auto& i : getOzelliker())
        {
            collector = collector + ((i.x * i.y * i.z) / 6000);
        }
        setVolumeWeight(collector);
    }

    float AirCargoBase::getChargableWeight() const
    {
        float chargableWeightHolder = 0;
        if (getWeightKG() <= getVolumeWeight())
        {
            return getVolumeWeight();
        }
        else
        {
            return getWeightKG();
        }
    }

#if 0
    void AirCargoBase::renderHavaNavlun()
    {
        output =    std::format("Pieces: {0}\n", getPieces());
        output +=   std::format("Weight: (KGs) {0:.3f} KG\n", getWeightKG());
        output +=   std::format("Volumetric weight: {0:.3f}\n", getVolumeWeight());
        output +=   std::format("Chargable weight: {0:.3f}\n", chargableWeightHolder);

        if (getWeightKG() <= getVolumeWeight())
            chargableWeightHolder =  getVolumeWeight();
        else
            chargableWeightHolder =  getWeightKG();
    
        ImGui::Text(output.c_str());

        ImGui::Separator();

        ImGui::PushItemWidth(110);
        ImGui::Text("Adet:                     "); ImGui::SameLine(); ImGui::InputScalar("##Adet", ImGuiDataType_U32, &Adet);

        ImGui::Text("Uzunluk:                "); ImGui::SameLine(); ImGui::InputFloat("##Length", &length_cm, 0.0f, 0.0f, "%.4f", ImGuiInputTextFlags_CharsScientific);
        ImGui::SameLine();
        displayUnitRadioButtons("length_unit", &length_unit);

        ImGui::Text("Geniþlik:                "); ImGui::SameLine(); ImGui::InputFloat("##Width", &width_cm, 0.0f, 0.0f, "%.4f", ImGuiInputTextFlags_CharsScientific);
        ImGui::SameLine();
        displayUnitRadioButtons("width_unit", &width_unit);

        ImGui::Text("Yükseklik:              "); ImGui::SameLine(); ImGui::InputFloat("##Height", &height_cm, 0.0f, 0.0f, "%.4f", ImGuiInputTextFlags_CharsScientific);
        ImGui::SameLine();
        displayUnitRadioButtons("height_unit", &height_unit);

        ImGui::Text("Input the Weight: "); ImGui::SameLine();

        if (ImGui::InputFloat("##WeightKGs", &weightKGHolder))
        {
            setWeightKG(weightKGHolder);
        }
        ImGui::PopItemWidth();

        ImGui::Separator();

        if (ImGui::Button("Ekle", { 120,0 }))
        {
            Vec3 stuff{};

            stuff.x = convertToCentimeters(length_cm, length_unit);
            stuff.y = convertToCentimeters(width_cm, width_unit);
            stuff.z = convertToCentimeters(height_cm, height_unit);
            pushValueToOzelliker(stuff, Adet);
            volumeWeightCalc();
        }
        ImGui::SameLine();
        if (ImGui::Button("Reset/Temizle", { 120,0 }))
        {
            clearOzellikler();
            setVolumeWeight(0);
            setWeightKG(0);
            weightKGHolder = getWeightKG();
        }
        ImGui::SameLine();
        if (ImGui::Button("Verileri Kopyala", { 120,0 }))
        {
            CopyClipboard(output);
        }
    }
#endif
}