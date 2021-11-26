// dllmain.cpp : Définit le point d'entrée de l'application DLL.
#include "pch.h"
#include "dllmain.h"

BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    if (ul_reason_for_call == DLL_PROCESS_ATTACH)
    {
        DisableThreadLibraryCalls(hModule);

        // TODO: Enable/Disable from config
        ENABLECONSOLE();

        auto hook = OniHook::GetInstance();
        hook->Hook();
    }

    return TRUE;
}

