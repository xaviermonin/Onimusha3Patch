// dllmain.cpp : Définit le point d'entrée de l'application DLL.
#include "pch.h"

#include <iostream>
#include <detours.h>
#include "Trace.h"
#include "Utils.h"
#include <d3d9helper.h>
#include "MyIDirect3D9.h"
#include "OniHook.h"

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	if (ul_reason_for_call == DLL_PROCESS_ATTACH)
	{
		DisableThreadLibraryCalls(hModule);
		Utils::EnableConsole();

		auto hook = OniHook::GetInstance();
		hook->Hook();
	}

	return TRUE;
}

