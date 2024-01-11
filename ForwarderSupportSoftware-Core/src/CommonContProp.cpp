#include "CommonContProp.h"

const std::string& CommonContProp::getContainerNumber() const
{
	return this->cntNumber;
}

const std::string& CommonContProp::getStatusDescription() const
{
	return this->statusDescription;
}

const std::string& CommonContProp::getLocation() const
{
	return this->location;
}

const std::string& CommonContProp::getTimeOfIssue() const
{
	return this->timeOfIssue;
}

const std::string& CommonContProp::getPodEta() const
{
	return this->podEta;
}

void CommonContProp::setContainerNumber(std::string cntNumber)
{
	this->cntNumber = cntNumber;
}

void CommonContProp::setStatusDescription(std::string statusDescription)
{
	this->statusDescription = statusDescription;
}

void CommonContProp::setLocation(std::string location)
{
	this->location = location;
}

void CommonContProp::setTimeOfIssue(std::string timeOfIssue)
{
	this->timeOfIssue = timeOfIssue;
}

void CommonContProp::setPodEta(std::string podEta)
{
	this->podEta = podEta;
}

bool runCurlProcess(std::string command, std::string& curlData)
{
	FILE* pipe = _popen(command.c_str(), "r"); // Use _popen for Windows

	if (!pipe) {
		return false;
	}
	else {
		char buffer[128];
		curlData = "";

		while (fgets(buffer, sizeof(buffer), pipe) != NULL) {
			curlData += buffer;
		}
		_pclose(pipe); // Use _pclose for Windows
	}
	return true;
}