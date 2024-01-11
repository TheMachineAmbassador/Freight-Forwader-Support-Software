#ifndef COSCOTRACKING_H
#define COSCOTRACKING_H

#include "CommonContProp.h"

#include <string>

class CoscoTracking : public CommonContProp
{
private:

public:
	const std::string& getContainerNumber() const override;
	const std::string& getStatusDescription() const override;
	const std::string& getLocation() const override;
	const std::string& getTimeOfIssue() const override;

	bool requestContainerData(std::string& ContainerNumber) override;
};

#endif