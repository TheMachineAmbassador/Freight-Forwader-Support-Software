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
    std::string rq = "curl -X POST -H \"X-Requested-With:XMLHttpRequest\" -H \"Content-Type:application/json\" -d ";
	rq += " \"{\\\"trackingNumber\\\":\\\" " + ContainerNumber + "\\\", \\\"trackingMode\\\": 0}\" https://www.msc.com/api/feature/tools/TrackingInfo";
    
	
	runCurlProcess(rq, curlData);
	try
	{
		jsonData = nlohmann::json::parse(curlData);
	}
	catch (const std::exception& e)
	{
		return false;
	}
    
	if (jsonData["IsSuccess"] == false)
		return false;

    return true;
}
