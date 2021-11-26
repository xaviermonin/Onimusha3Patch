#pragma once

#ifdef _DEBUG
#define ENABLECONSOLE() Utils::EnableConsole()
#else
#define ENABLECONSOLE()
#endif

class Utils
{
public:
	static void EnableConsole();
	static FARPROC LoadProcAddress(LPCSTR moduleName, LPCSTR procName);
};
