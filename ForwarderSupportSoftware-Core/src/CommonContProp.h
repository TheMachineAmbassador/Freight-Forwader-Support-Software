#ifndef COMMONCONTPROP_H
#define COMMONCONTPROP_H

#include <string>

#include "nlohmann/json.hpp"


class CommonContProp
{
private:
	std::string cntNumber;
	std::string statusDescription;
	std::string location;
	std::string timeOfIssue;
	std::string podEta;

protected:
	// TODO(This s need to be simplifield)
	nlohmann::json jsonData;

	void setContainerNumber(std::string cntNumber);
	void setStatusDescription(std::string statusDescription);
	void setLocation(std::string location);
	void setTimeOfIssue(std::string timeOfIssue);
	void setPodEta(std::string podEta);

public:
	virtual const std::string& getContainerNumber() const;
	virtual const std::string& getStatusDescription() const;
	virtual const std::string& getLocation() const;
	virtual const std::string& getTimeOfIssue() const;
	virtual const std::string& getPodEta() const;

	virtual bool requestContainerData(std::string& ContainerNumber) { return false; };
};

extern bool runCurlGetRequest(const std::string& url, std::string& responseData);
extern bool runCurlPostRequest(const std::string& url, const std::string& postFields, std::string& responseData);

#endif // COMMONCONTPROP_H