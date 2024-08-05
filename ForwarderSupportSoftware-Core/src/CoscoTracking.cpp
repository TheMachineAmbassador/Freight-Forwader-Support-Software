#include "CoscoTracking.h"

const std::string& CoscoTracking::getContainerNumber() const
{
	return jsonData["data"]["content"]["containers"][0]["container"]["containerNumber"];
}

const std::string& CoscoTracking::getStatusDescription() const
{
	return jsonData["data"]["content"]["containers"][0]["containerCircleStatus"][0]["containerNumberStatus"];
}

const std::string& CoscoTracking::getLocation() const
{
	return jsonData["data"]["content"]["containers"][0]["containerCircleStatus"][0]["location"];
}

const std::string& CoscoTracking::getTimeOfIssue() const
{
	return jsonData["data"]["content"]["containers"][0]["containerCircleStatus"][0]["timeOfIssue"];
}


bool CoscoTracking::requestContainerData(std::string& ContainerNumber)
{
	std::string curlData;
	std::string command = "https://elines.coscoshipping.com/ebtracking/public/containers/" + ContainerNumber;

	std::string curlEtaData;
	std::string curlEtaCommand = "https://elines.coscoshipping.com/ebtracking/public/container/eta/" + ContainerNumber;

	if (!runCurlGetRequest(command, curlData) || !runCurlGetRequest(curlEtaCommand, curlEtaData)) {
		return false;
	}

	try
	{
		setPodEta(nlohmann::json::parse(curlEtaData)["data"]["content"]);
		jsonData = nlohmann::json::parse(curlData);
	}
	catch (const std::exception& e) {
		return false;
	}

	if (jsonData["IsSuccess"] == false)
		return false;

	return true;
}
