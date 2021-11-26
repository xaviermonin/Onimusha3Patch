#include "pch.h"
#include "OniHook.h"

CreateWindowExWType OniHook::TrueCreateWindowExW = nullptr;
Direct3DCreate9Type OniHook::TrueDirect3DCreate9 = nullptr;
OniHook *OniHook::instance = nullptr;

HWND WINAPI OniHook::MyCreateWindowExW(
    DWORD dwExStyle,
    _In_opt_ LPCWSTR   lpClassName,
    _In_opt_ LPCWSTR   lpWindowName,
    _In_     DWORD     dwStyle,
    _In_     int       X,
    _In_     int       Y,
    _In_     int       nWidth,
    _In_     int       nHeight,
    _In_opt_ HWND      hWndParent,
    _In_opt_ HMENU     hMenu,
    _In_opt_ HINSTANCE hInstance,
    _In_opt_ LPVOID    lpParam
)
{
    TraceFunc();

    if (lpWindowName == NULL)
        exit(302);

    TraceParam("Window name", lpWindowName);

    if (!wcscmp(lpWindowName, L"oni3")) {
        TraceMsg("Oni window found");

        const DWORD borderLessStyle = WS_POPUP | WS_VISIBLE | WS_SYSMENU;
        const DWORD resizableStyle = WS_TILEDWINDOW;

        X = CW_USEDEFAULT;
        Y = CW_USEDEFAULT;

        // TODO: Read from config
        nWidth = 1920;
        nHeight = 1080;
        dwExStyle = WS_EX_APPWINDOW;
        dwStyle = resizableStyle;
    }

    HWND result = TrueCreateWindowExW(dwExStyle, lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam);

    if (result == NULL) {
        DWORD errorCode = GetLastError();
        std::cerr << "CreateWindowExW failed with error code " << errorCode << std::endl;
    }

    return result;
}

IDirect3D9 *WINAPI OniHook::MyDirect3DCreate9(UINT SDKVersion)
{
    TraceFunc();
    IDirect3D9 *d3d9 = TrueDirect3DCreate9(SDKVersion);

    return new MyIDirect3D9(d3d9);
}

void OniHook::LoadEntryPoints()
{
    TraceFunc();

    TrueCreateWindowExW = reinterpret_cast<CreateWindowExWType>(Utils::LoadProcAddress("user32", "CreateWindowExW"));
    TrueDirect3DCreate9 = reinterpret_cast<Direct3DCreate9Type>(Utils::LoadProcAddress("d3d9", "Direct3DCreate9"));
}

OniHook *OniHook::GetInstance()
{
    if (OniHook::instance == nullptr) {
        OniHook::instance = new OniHook();
    }

    return OniHook::instance;
}

void OniHook::Hook()
{
    TraceFunc();

    LoadEntryPoints();

    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());

    DetourAttach((PVOID *)&TrueDirect3DCreate9, MyDirect3DCreate9);
    DetourAttach((PVOID *)&TrueCreateWindowExW, MyCreateWindowExW);

    if (DetourTransactionCommit() != NO_ERROR) {
        std::cerr << "Detour failed";
    }
}

void OniHook::UnHook()
{
}
