#pragma once
#include <windows.h>
#include <iostream>

class Utils
{
public :
	static void EnableConsole() {
		if (AllocConsole()) {
			FILE* fDummy;
			freopen_s(&fDummy, "CONIN$", "r", stdin);
			freopen_s(&fDummy, "CONOUT$", "w", stderr);
			freopen_s(&fDummy, "CONOUT$", "w", stdout);
		}
	}

	static std::string WStringToString(const std::wstring& s)
	{
		std::string temp(s.length(), ' ');
		std::copy(s.begin(), s.end(), temp.begin());
		return temp;
	}

	static FARPROC LoadProcAddress(LPCSTR moduleName, LPCSTR procName) {
		std::cout << "Loading procedure " << procName << " from module " << moduleName << std::endl;

		HMODULE hModule = GetModuleHandleA(moduleName);

		if (hModule == NULL) {
			std::cout << moduleName << " not yet loaded. Loading..." << std::endl;
			hModule = LoadLibraryA(moduleName);
			if (hModule == NULL) {
				std::cerr << "Module " << moduleName << " not found" << std::endl;
				return NULL;
			}
		}

		FARPROC procAddr = GetProcAddress(hModule, procName);

		if (procAddr == NULL) {
			std::cerr << "Procedure " << procName << " not found" << std::endl;
			return NULL;
		}

		return procAddr;
	}
};
