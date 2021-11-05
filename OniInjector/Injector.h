#pragma once

#include <iostream>
#include <windows.h>

class Injector
{
private:
	std::string exePath;

private:
	PROCESS_INFORMATION RunProcess(const std::string processFileName) {
		STARTUPINFOA startupinfoa = { 0 };
		PROCESS_INFORMATION processInfo = { 0 };

		BOOL result = CreateProcessA(processFileName.c_str(), nullptr, nullptr,
			nullptr, FALSE, CREATE_SUSPENDED, nullptr,
			/*Attention*/nullptr,
			&startupinfoa, &processInfo);

		if (!result) {
			std::cerr << "RunProcess Error: " << GetLastError();
		}
		else {
			return processInfo;
		}
	}

	void InjectDll(HANDLE hProc, const std::string dllPath) {
		size_t dllPathSize = dllPath.length() + 1;

		LPVOID allocAddr = VirtualAllocEx(hProc, NULL, dllPathSize, MEM_COMMIT, PAGE_EXECUTE_READWRITE);

		if (allocAddr == NULL) {
			std::cerr << "Mem Alloc failed";
			return;
		}

		if (!WriteProcessMemory(hProc, allocAddr, dllPath.c_str(), dllPathSize, nullptr)) {
			std::cerr << "Write Memory failed";
			return;
		}

		DWORD dWord;
		auto loadLibraryAddr = (LPTHREAD_START_ROUTINE)GetProcAddress(LoadLibraryA("kernel32"), "LoadLibraryA");

		HANDLE hRemoteThread = CreateRemoteThread(hProc, NULL, 0, loadLibraryAddr, allocAddr, 0, &dWord);
		if (!hRemoteThread) {
			std::cerr << "CreateRemoteThread failed";
			return;
		}

		WaitForSingleObject(hRemoteThread, INFINITE);
	}

public:
	Injector(const std::string& exePath) {
		this->exePath = exePath;
	}

	void RunAndInject(const std::string& dllPath) {
		auto procInfo = RunProcess(this->exePath);
		InjectDll(procInfo.hProcess, dllPath);
		ResumeThread(procInfo.hThread);
	}
};

