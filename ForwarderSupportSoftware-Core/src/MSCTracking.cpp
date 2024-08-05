#include "MSCTracking.h"

const std::string& MSCContainer::getContainerNumber() const
{
	return jsonData["Data"]["BillOfLadings"][0]["ContainersInfo"][0]["ContainerNumber"];
}

const std::string& MSCContainer::getStatusDescription() const
{
	auto& containers = jsonData["Data"]["BillOfLadings"][0]["ContainersInfo"];
	auto& container = containers[0];
	auto& events = container["Events"];
	auto& latestEvent = events[0];
	auto& eventStatus = latestEvent["Description"];
	return eventStatus.get<std::string>();
}

const std::string& MSCContainer::getLocation() const
{
	auto& containers = jsonData["Data"]["BillOfLadings"][0]["ContainersInfo"];
	auto& container = containers[0];
	auto& events = container["Events"];
	auto& latestEvent = events[0];
	auto& eventLocation = latestEvent["Location"];
	return eventLocation;
}

const std::string& MSCContainer::getTimeOfIssue() const
{
	auto& containers = jsonData["Data"]["BillOfLadings"][0]["ContainersInfo"];
	auto& container = containers[0];
	auto& events = container["Events"];
	auto& latestEvent = events[0];
	auto& eventDate = latestEvent["Date"];

	return eventDate.get<std::string>();
}

const std::string& MSCContainer::getPodEta() const
{
	return jsonData["Data"]["BillOfLadings"][0]["ContainersInfo"][0]["PodEtaDate"];
}

bool MSCContainer::requestContainerData(std::string& ContainerNumber)
{
	std::string curlData;
	std::string url = "https://www.msc.com/api/feature/tools/TrackingInfo";

	// JSON payload as a string
	std::string postFields = "{\"trackingNumber\":\"" + ContainerNumber + "\", \"trackingMode\": 0}";

	// Run the curl request
	if (!runCurlPostRequest(url, postFields, curlData)) {
		return false;
	}

	try {
		jsonData = nlohmann::json::parse(curlData);
	}
	catch (const std::exception& e) {
		assert ("JSON Parsing failed: " << e.what());
		return false;
	}

	if (jsonData["IsSuccess"] == false)
		return false;

	return true;

}
