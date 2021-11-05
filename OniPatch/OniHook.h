#pragma once

#include <detours.h>
#include "Trace.h"
#include <d3d9helper.h>
#include "Utils.h"
#include "MyIDirect3D9.h"

// Type
typedef HWND(WINAPI* CreateWindowExWType) (
	_In_ DWORD dwExStyle,
	_In_opt_ LPCWSTR lpClassName,
	_In_opt_ LPCWSTR lpWindowName,
	_In_ DWORD dwStyle,
	_In_ int X,
	_In_ int Y,
	_In_ int nWidth,
	_In_ int nHeight,
	_In_opt_ HWND hWndParent,
	_In_opt_ HMENU hMenu,
	_In_opt_ HINSTANCE hInstance,
	_In_opt_ LPVOID lpParam);

typedef IDirect3D9* (WINAPI* Direct3DCreate9Type) (UINT SDKVersion);

class OniHook
{
private:
	static OniHook* instance;
public:
	static CreateWindowExWType TrueCreateWindowExW;
	static Direct3DCreate9Type TrueDirect3DCreate9;

	// Hooks

	static HWND WINAPI MyCreateWindowExW(
		DWORD dwExStyle,
		_In_opt_ LPCWSTR lpClassName,
		_In_opt_ LPCWSTR lpWindowName,
		_In_ DWORD dwStyle,
		_In_ int X,
		_In_ int Y,
		_In_ int nWidth,
		_In_ int nHeight,
		_In_opt_ HWND hWndParent,
		_In_opt_ HMENU hMenu,
		_In_opt_ HINSTANCE hInstance,
		_In_opt_ LPVOID lpParam)
	{
		TraceFunc();

		std::string windowName;

		if (lpWindowName != NULL) {
			windowName = Utils::WStringToString(lpWindowName);
		}

		TraceParam("Window name", windowName);

		if (windowName == "oni3") {
			TraceMsg("Oni window found");

			const DWORD fullscreenBorderless = WS_POPUP | WS_VISIBLE | WS_SYSMENU;
			const DWORD resizableWindow = WS_TILEDWINDOW;

			X = CW_USEDEFAULT;
			Y = CW_USEDEFAULT;
			nWidth = 1920;
			nHeight = 1080;
			dwExStyle = WS_EX_APPWINDOW;
			dwStyle = resizableWindow;
		}

		HWND result = TrueCreateWindowExW(dwExStyle, lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam);

		if (result == NULL) {
			DWORD errorCode = GetLastError();
			std::cerr << "CreateWindowExW failed with error code " << errorCode << std::endl;
		}

		return result;
	}

	static IDirect3D9* WINAPI MyDirect3DCreate9(
		UINT SDKVersion
	) {
		TraceFunc();
		IDirect3D9* d3d9 = TrueDirect3DCreate9(SDKVersion);

		return new MyIDirect3D9(d3d9);
	}

	void LoadEntryPoints() {
		TraceFunc();

		TrueCreateWindowExW = reinterpret_cast<CreateWindowExWType>(Utils::LoadProcAddress("user32", "CreateWindowExW"));
		TrueDirect3DCreate9 = reinterpret_cast<Direct3DCreate9Type>(Utils::LoadProcAddress("d3d9", "Direct3DCreate9"));
	}

	static OniHook* GetInstance() {
		if (OniHook::instance == nullptr) {
			OniHook::instance = new OniHook();
		}

		return OniHook::instance;
	}

	void Hook() {
		TraceFunc();

		LoadEntryPoints();

		DetourTransactionBegin();
		DetourUpdateThread(GetCurrentThread());

		DetourAttach((PVOID*)&TrueDirect3DCreate9, MyDirect3DCreate9);
		DetourAttach((PVOID*)&TrueCreateWindowExW, MyCreateWindowExW);

		if (DetourTransactionCommit() != NO_ERROR) {
			std::cerr << "Detour failed";
		}
	}

	void UnHook() {	}
};

CreateWindowExWType OniHook::TrueCreateWindowExW = nullptr;
Direct3DCreate9Type OniHook::TrueDirect3DCreate9 = nullptr;
OniHook* OniHook::instance = nullptr;