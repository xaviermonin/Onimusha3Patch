#pragma once
#include <iostream>

#define TraceFunc() Trace __log = Trace(__FUNCTION__)
#define TraceParam(ParamName, ParamValue) __log.TraceParameter(ParamName, ParamValue)
#define TraceMsg(Message) __log.TraceMessage(Message)

class Trace
{
private:
	std::string functionName;

public:
	Trace(const std::string& functionName) {
		this->functionName = functionName;

		std::cout << "[Enter Function] " << this->functionName << std::endl;
	}

	template <typename T>
	void TraceParameter(const std::string& parameterName, const T& parameter) {
		std::cout << "\t" << parameterName << ": " << parameter << std::endl;
	}

	void TraceMessage(const std::string message) {
		std::cout << "\t" << message << std::endl;
	}

	~Trace() {
		std::cout << "[Exit Function] " << this->functionName << std::endl;
	}
};
