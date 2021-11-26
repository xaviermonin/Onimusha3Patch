#pragma once

#include "pch.h"
#include "Utils.h"
#include "Trace.h"
#include "MyIDirect3D9.h"

// Type
typedef HWND(WINAPI *CreateWindowExWType) (
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

typedef IDirect3D9 *(WINAPI *Direct3DCreate9Type) (UINT SDKVersion);

class OniHook
{
private:
	static OniHook *instance;
public:
	static CreateWindowExWType TrueCreateWindowExW;
	static Direct3DCreate9Type TrueDirect3DCreate9;

	// Hooks
	static HWND WINAPI MyCreateWindowExW(DWORD dwExStyle, _In_opt_ LPCWSTR lpClassName, _In_opt_ LPCWSTR lpWindowName, _In_ DWORD dwStyle, _In_ int X, _In_ int Y, _In_ int nWidth, _In_ int nHeight, _In_opt_ HWND hWndParent, _In_opt_ HMENU hMenu, _In_opt_ HINSTANCE hInstance, _In_opt_ LPVOID lpParam);
	static IDirect3D9 *WINAPI MyDirect3DCreate9(UINT SDKVersion);
	void LoadEntryPoints();
	static OniHook *GetInstance();
	void Hook();
	void UnHook();
};
