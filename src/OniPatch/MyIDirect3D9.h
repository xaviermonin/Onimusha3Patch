#pragma once

#include <d3d9helper.h>
#include "Trace.h"
#include "MyIDirect3DDevice9.h"

class MyIDirect3D9 : public IDirect3D9
{
private:
	IDirect3D9* original;
public:
	MyIDirect3D9(IDirect3D9* original) {
		this->original = original;
		this->Version = this->original->Version;
	}

	virtual ~MyIDirect3D9() {

	}

	/*** IUnknown methods ***/
	STDMETHOD(QueryInterface)(THIS_ REFIID riid, void** ppvObj) {
		return this->original->QueryInterface(riid, ppvObj);
	}

	STDMETHOD_(ULONG, AddRef)(THIS) {
		return this->original->AddRef();
	}

	STDMETHOD_(ULONG, Release)(THIS) {
		return this->original->Release();
	}

	/*** IDirect3D9 methods ***/
	STDMETHOD(RegisterSoftwareDevice)(THIS_ void* pInitializeFunction) {
		return this->original->RegisterSoftwareDevice(pInitializeFunction);
	}

	STDMETHOD_(UINT, GetAdapterCount)(THIS) {
		return this->original->GetAdapterCount();
	}

	STDMETHOD(GetAdapterIdentifier)(THIS_ UINT Adapter, DWORD Flags, D3DADAPTER_IDENTIFIER9* pIdentifier) {
		return this->original->GetAdapterIdentifier(Adapter, Flags, pIdentifier);
	}

	STDMETHOD_(UINT, GetAdapterModeCount)(THIS_ UINT Adapter, D3DFORMAT Format) {
		return this->original->GetAdapterCount();
	}

	STDMETHOD(EnumAdapterModes)(THIS_ UINT Adapter, D3DFORMAT Format, UINT Mode, D3DDISPLAYMODE* pMode) {
		return this->original->EnumAdapterModes(Adapter, Format, Mode, pMode);
	}

	STDMETHOD(GetAdapterDisplayMode)(THIS_ UINT Adapter, D3DDISPLAYMODE* pMode) {
		return this->original->GetAdapterDisplayMode(Adapter, pMode);
	}

	STDMETHOD(CheckDeviceType)(THIS_ UINT iAdapter, D3DDEVTYPE DevType, D3DFORMAT DisplayFormat, D3DFORMAT BackBufferFormat, BOOL bWindowed) {
		return this->original->CheckDeviceType(iAdapter, DevType, DisplayFormat, BackBufferFormat, bWindowed);
	}

	STDMETHOD(CheckDeviceFormat)(THIS_ UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, DWORD Usage, D3DRESOURCETYPE RType, D3DFORMAT CheckFormat) {
		return this->original->CheckDeviceFormat(Adapter, DeviceType, AdapterFormat, Usage, RType, CheckFormat);
	}

	STDMETHOD(CheckDeviceMultiSampleType)(THIS_ UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT SurfaceFormat, BOOL Windowed, D3DMULTISAMPLE_TYPE MultiSampleType, DWORD* pQualityLevels) {
		return this->original->CheckDeviceMultiSampleType(Adapter, DeviceType, SurfaceFormat, Windowed, MultiSampleType, pQualityLevels);
	}

	STDMETHOD(CheckDepthStencilMatch)(THIS_ UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, D3DFORMAT RenderTargetFormat, D3DFORMAT DepthStencilFormat) {
		return this->original->CheckDepthStencilMatch(Adapter, DeviceType, AdapterFormat, RenderTargetFormat, DepthStencilFormat);
	}

	STDMETHOD(CheckDeviceFormatConversion)(THIS_ UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT SourceFormat, D3DFORMAT TargetFormat) {
		return this->original->CheckDeviceFormatConversion(Adapter, DeviceType, SourceFormat, TargetFormat);
	}

	STDMETHOD(GetDeviceCaps)(THIS_ UINT Adapter, D3DDEVTYPE DeviceType, D3DCAPS9* pCaps) {
		return this->original->GetDeviceCaps(Adapter, DeviceType, pCaps);
	}

	STDMETHOD_(HMONITOR, GetAdapterMonitor)(THIS_ UINT Adapter) {
		return this->original->GetAdapterMonitor(Adapter);
	}

	STDMETHOD(CreateDevice)(THIS_ UINT Adapter, D3DDEVTYPE DeviceType, HWND hFocusWindow, DWORD BehaviorFlags, D3DPRESENT_PARAMETERS* pPresentationParameters, IDirect3DDevice9** ppReturnedDeviceInterface) {
		TraceFunc();

		TraceParam("BackBufferWidth", pPresentationParameters->BackBufferWidth);
		TraceParam("BackBufferHeight", pPresentationParameters->BackBufferHeight);
		TraceParam("Windowed", pPresentationParameters->Windowed);
		TraceParam("MultiSampleType", pPresentationParameters->MultiSampleType);
		TraceParam("MultiSampleQuality", pPresentationParameters->MultiSampleQuality);
		TraceParam("SwapEffect", pPresentationParameters->SwapEffect);
		TraceParam("AutoDepthStencilFormat", pPresentationParameters->AutoDepthStencilFormat);
		TraceParam("PresentationInterval", pPresentationParameters->PresentationInterval);
		
		if (pPresentationParameters->BackBufferWidth == 800) {

			TraceMsg("Back buffer updated");

			/*pPresentationParameters->BackBufferWidth = 3840;
			pPresentationParameters->BackBufferHeight = 2160;*/

			// TODO: Read this from configuration
			pPresentationParameters->BackBufferWidth = 1920;
			pPresentationParameters->BackBufferHeight = 1080;
			
			//pPresentationParameters->Windowed = FALSE;
		}

		IDirect3DDevice9* trueDevice = nullptr;

		HRESULT hResult = this->original->CreateDevice(Adapter, DeviceType, hFocusWindow, BehaviorFlags, pPresentationParameters, &trueDevice);

		(*ppReturnedDeviceInterface) = new MyIDirect3DDevice9(trueDevice);

		return hResult;
	}

	/*** Helper information ***/
	LPCWSTR Version;
};

