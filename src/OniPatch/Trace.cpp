#include "pch.h"
#include "Trace.h"


Trace::Trace(const std::string &functionName)
{
	this->functionName = functionName;

	std::cout << "[Enter Function] " << this->functionName << std::endl;
}

void Trace::TraceMessage(const std::string message)
{
	std::cout << "\t" << message << std::endl;
}

Trace::~Trace()
{
	std::cout << "[Exit Function] " << this->functionName << std::endl;
}
