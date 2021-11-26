#pragma once

#ifdef _DEBUG
#define TraceFunc() Trace __log = Trace(__FUNCTION__)
#define TraceParam(ParamName, ParamValue) __log.TraceParameter(ParamName, ParamValue)
#define TraceMsg(Message) __log.TraceMessage(Message)
#else
#define TraceFunc()
#define TraceParam(ParamName, ParamValue)
#define TraceMsg(Message)
#endif

class Trace
{
private:
    std::string functionName;

public:
    Trace(const std::string &functionName);

    template <typename T>
    void TraceParameter(const std::string &parameterName, const T &parameter)
    {
        std::cout << "\t" << parameterName << ": " << parameter << std::endl;
    }

    void TraceMessage(const std::string message);
    ~Trace();
};
