#ifndef MSCTRACKING_H
#define MSCTRACKING_H

#include "CommonContProp.h"

class MSCContainer : public CommonContProp
{
private:

public:
	const std::string& getContainerNumber() const override;
	const std::string& getStatusDescription() const override;
	const std::string& getLocation() const override;
	const std::string& getTimeOfIssue() const override;
	const std::string& getPodEta() const override;

	bool requestContainerData(std::string& ContainerNumber) override;
};

#endif // MSCTRACKING_H