#pragma once
#include <d3d9helper.h>
#include "Trace.h"

class MyIDirect3DDevice9 : public IDirect3DDevice9
{
private:
    IDirect3DDevice9* original;

public:
    MyIDirect3DDevice9(IDirect3DDevice9* original) {
        this->original = original;
        //(&(this->CreationParameters)) = this->original->CreationParameters;
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

    /*** IDirect3DDevice9 methods ***/
    STDMETHOD(TestCooperativeLevel)(THIS) {
        return this->original->TestCooperativeLevel();
    }

    STDMETHOD_(UINT, GetAvailableTextureMem)(THIS) {
        return this->original->GetAvailableTextureMem();
    }

    STDMETHOD(EvictManagedResources)(THIS) {
        return this->original->EvictManagedResources();
    }

    STDMETHOD(GetDirect3D)(THIS_ IDirect3D9** ppD3D9) {
        return this->original->GetDirect3D(ppD3D9);
    }

    STDMETHOD(GetDeviceCaps)(THIS_ D3DCAPS9* pCaps) {
        return this->original->GetDeviceCaps(pCaps);
    }

    STDMETHOD(GetDisplayMode)(THIS_ UINT iSwapChain, D3DDISPLAYMODE* pMode) {
        return this->original->GetDisplayMode(iSwapChain, pMode);
    }

    STDMETHOD(GetCreationParameters)(THIS_ D3DDEVICE_CREATION_PARAMETERS* pParameters) {
        return this->original->GetCreationParameters(pParameters);
    }

    STDMETHOD(SetCursorProperties)(THIS_ UINT XHotSpot, UINT YHotSpot, IDirect3DSurface9* pCursorBitmap) {
        return this->original->SetCursorProperties(XHotSpot, YHotSpot, pCursorBitmap);
    }

    STDMETHOD_(void, SetCursorPosition)(THIS_ int X, int Y, DWORD Flags) {
        return this->original->SetCursorPosition(X, Y, Flags);
    }

    STDMETHOD_(BOOL, ShowCursor)(THIS_ BOOL bShow) {
        return this->original->ShowCursor(bShow);
    }

    STDMETHOD(CreateAdditionalSwapChain)(THIS_ D3DPRESENT_PARAMETERS* pPresentationParameters, IDirect3DSwapChain9** pSwapChain) {
        return this->original->CreateAdditionalSwapChain(pPresentationParameters, pSwapChain);
    }

    STDMETHOD(GetSwapChain)(THIS_ UINT iSwapChain, IDirect3DSwapChain9** pSwapChain) {
        return this->original->GetSwapChain(iSwapChain, pSwapChain);
    }

    STDMETHOD_(UINT, GetNumberOfSwapChains)(THIS) {
        return this->original->GetNumberOfSwapChains();
    }

    STDMETHOD(Reset)(THIS_ D3DPRESENT_PARAMETERS* pPresentationParameters) {
        return this->original->Reset(pPresentationParameters);
    }

    STDMETHOD(Present)(THIS_ CONST RECT* pSourceRect, CONST RECT* pDestRect, HWND hDestWindowOverride, CONST RGNDATA* pDirtyRegion) {
        return this->original->Present(pSourceRect, pDestRect, hDestWindowOverride, pDirtyRegion);
    }

    STDMETHOD(GetBackBuffer)(THIS_ UINT iSwapChain, UINT iBackBuffer, D3DBACKBUFFER_TYPE Type, IDirect3DSurface9** ppBackBuffer) {
        return this->original->GetBackBuffer(iSwapChain, iBackBuffer, Type, ppBackBuffer);
    }

    STDMETHOD(GetRasterStatus)(THIS_ UINT iSwapChain, D3DRASTER_STATUS* pRasterStatus) {
        return this->original->GetRasterStatus(iSwapChain, pRasterStatus);
    }

    STDMETHOD(SetDialogBoxMode)(THIS_ BOOL bEnableDialogs) {
        return this->original->SetDialogBoxMode(bEnableDialogs);
    }

    STDMETHOD_(void, SetGammaRamp)(THIS_ UINT iSwapChain, DWORD Flags, CONST D3DGAMMARAMP* pRamp) {
        return this->original->SetGammaRamp(iSwapChain, Flags, pRamp);
    }

    STDMETHOD_(void, GetGammaRamp)(THIS_ UINT iSwapChain, D3DGAMMARAMP* pRamp) {
        return this->original->GetGammaRamp(iSwapChain, pRamp);
    }

    STDMETHOD(CreateTexture)(THIS_ UINT Width, UINT Height, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DTexture9** ppTexture, HANDLE* pSharedHandle) {
        return this->original->CreateTexture(Width, Height, Levels, Usage, Format, Pool, ppTexture, pSharedHandle);
    }

    STDMETHOD(CreateVolumeTexture)(THIS_ UINT Width, UINT Height, UINT Depth, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DVolumeTexture9** ppVolumeTexture, HANDLE* pSharedHandle) {
        return this->original->CreateVolumeTexture(Width, Height, Depth, Levels, Usage, Format, Pool, ppVolumeTexture, pSharedHandle);
    }

    STDMETHOD(CreateCubeTexture)(THIS_ UINT EdgeLength, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DCubeTexture9** ppCubeTexture, HANDLE* pSharedHandle) {
        return this->original->CreateCubeTexture(EdgeLength, Levels, Usage, Format, Pool, ppCubeTexture, pSharedHandle);
    }

    STDMETHOD(CreateVertexBuffer)(THIS_ UINT Length, DWORD Usage, DWORD FVF, D3DPOOL Pool, IDirect3DVertexBuffer9** ppVertexBuffer, HANDLE* pSharedHandle) {
        return this->original->CreateVertexBuffer(Length, Usage, FVF, Pool, ppVertexBuffer, pSharedHandle);
    }

    STDMETHOD(CreateIndexBuffer)(THIS_ UINT Length, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DIndexBuffer9** ppIndexBuffer, HANDLE* pSharedHandle) {
        return this->original->CreateIndexBuffer(Length, Usage, Format, Pool, ppIndexBuffer, pSharedHandle);
    }

    STDMETHOD(CreateRenderTarget)(THIS_ UINT Width, UINT Height, D3DFORMAT Format, D3DMULTISAMPLE_TYPE MultiSample, DWORD MultisampleQuality, BOOL Lockable, IDirect3DSurface9** ppSurface, HANDLE* pSharedHandle) {
        return this->original->CreateRenderTarget(Width, Height, Format, MultiSample, MultisampleQuality, Lockable, ppSurface, pSharedHandle);
    }

    STDMETHOD(CreateDepthStencilSurface)(THIS_ UINT Width, UINT Height, D3DFORMAT Format, D3DMULTISAMPLE_TYPE MultiSample, DWORD MultisampleQuality, BOOL Discard, IDirect3DSurface9** ppSurface, HANDLE* pSharedHandle) {
        return this->original->CreateDepthStencilSurface(Width, Height, Format, MultiSample, MultisampleQuality, Discard, ppSurface, pSharedHandle);
    }

    STDMETHOD(UpdateSurface)(THIS_ IDirect3DSurface9* pSourceSurface, CONST RECT* pSourceRect, IDirect3DSurface9* pDestinationSurface, CONST POINT* pDestPoint) {
        return this->original->UpdateSurface(pSourceSurface, pSourceRect, pDestinationSurface, pDestPoint);
    }

    STDMETHOD(UpdateTexture)(THIS_ IDirect3DBaseTexture9* pSourceTexture, IDirect3DBaseTexture9* pDestinationTexture) {
        return this->original->UpdateTexture(pSourceTexture, pDestinationTexture);
    }

    STDMETHOD(GetRenderTargetData)(THIS_ IDirect3DSurface9* pRenderTarget, IDirect3DSurface9* pDestSurface) {
        return this->original->GetRenderTargetData(pRenderTarget, pDestSurface);
    }

    STDMETHOD(GetFrontBufferData)(THIS_ UINT iSwapChain, IDirect3DSurface9* pDestSurface) {
        return this->original->GetFrontBufferData(iSwapChain, pDestSurface);
    }

    STDMETHOD(StretchRect)(THIS_ IDirect3DSurface9* pSourceSurface, CONST RECT* pSourceRect, IDirect3DSurface9* pDestSurface, CONST RECT* pDestRect, D3DTEXTUREFILTERTYPE Filter) {
        return this->original->StretchRect(pSourceSurface, pSourceRect, pDestSurface, pDestRect, Filter);
    }

    STDMETHOD(ColorFill)(THIS_ IDirect3DSurface9* pSurface, CONST RECT* pRect, D3DCOLOR color) {
        return this->original->ColorFill(pSurface, pRect, color);
    }

    STDMETHOD(CreateOffscreenPlainSurface)(THIS_ UINT Width, UINT Height, D3DFORMAT Format, D3DPOOL Pool, IDirect3DSurface9** ppSurface, HANDLE* pSharedHandle) {
        return this->original->CreateOffscreenPlainSurface(Width, Height, Format, Pool, ppSurface, pSharedHandle);
    }

    STDMETHOD(SetRenderTarget)(THIS_ DWORD RenderTargetIndex, IDirect3DSurface9* pRenderTarget) {
        return this->original->SetRenderTarget(RenderTargetIndex, pRenderTarget);
    }

    STDMETHOD(GetRenderTarget)(THIS_ DWORD RenderTargetIndex, IDirect3DSurface9** ppRenderTarget) {
        return this->original->GetRenderTarget(RenderTargetIndex, ppRenderTarget);
    }

    STDMETHOD(SetDepthStencilSurface)(THIS_ IDirect3DSurface9* pNewZStencil) {
        return this->original->SetDepthStencilSurface(pNewZStencil);
    }

    STDMETHOD(GetDepthStencilSurface)(THIS_ IDirect3DSurface9** ppZStencilSurface) {
        return this->original->GetDepthStencilSurface(ppZStencilSurface);
    }

    STDMETHOD(BeginScene)(THIS) {
        return this->original->BeginScene();
    }

    STDMETHOD(EndScene)(THIS) {
        return this->original->EndScene();
    }

    STDMETHOD(Clear)(THIS_ DWORD Count, CONST D3DRECT* pRects, DWORD Flags, D3DCOLOR Color, float Z, DWORD Stencil) {
        return this->original->Clear(Count, pRects, Flags, Color, Z, Stencil);
    }

    STDMETHOD(SetTransform)(THIS_ D3DTRANSFORMSTATETYPE State, CONST D3DMATRIX* pMatrix) {
        return this->original->SetTransform(State, pMatrix);
    }

    STDMETHOD(GetTransform)(THIS_ D3DTRANSFORMSTATETYPE State, D3DMATRIX* pMatrix) {
        return this->original->GetTransform(State, pMatrix);
    }

    STDMETHOD(MultiplyTransform)(THIS_ D3DTRANSFORMSTATETYPE State, CONST D3DMATRIX* pMatrix) {
        return this->original->MultiplyTransform(State, pMatrix);
    }

    STDMETHOD(SetViewport)(THIS_ CONST D3DVIEWPORT9* pViewport) {
        return this->original->SetViewport(pViewport);
    }

    STDMETHOD(GetViewport)(THIS_ D3DVIEWPORT9* pViewport) {
        return this->original->GetViewport(pViewport);
    }

    STDMETHOD(SetMaterial)(THIS_ CONST D3DMATERIAL9* pMaterial) {
        return this->original->SetMaterial(pMaterial);
    }

    STDMETHOD(GetMaterial)(THIS_ D3DMATERIAL9* pMaterial) {
        return this->original->GetMaterial(pMaterial);
    }

    STDMETHOD(SetLight)(THIS_ DWORD Index, CONST D3DLIGHT9* pLight) {
        return this->original->SetLight(Index, pLight);
    }

    STDMETHOD(GetLight)(THIS_ DWORD Index, D3DLIGHT9* pLight) {
        return this->original->GetLight(Index, pLight);
    }

    STDMETHOD(LightEnable)(THIS_ DWORD Index, BOOL Enable) {
        return this->original->LightEnable(Index, Enable);
    }

    STDMETHOD(GetLightEnable)(THIS_ DWORD Index, BOOL* pEnable) {
        return this->original->GetLightEnable(Index, pEnable);
    }

    STDMETHOD(SetClipPlane)(THIS_ DWORD Index, CONST float* pPlane) {
        return this->original->SetClipPlane(Index, pPlane);
    }

    STDMETHOD(GetClipPlane)(THIS_ DWORD Index, float* pPlane) {
        return this->original->GetClipPlane(Index, pPlane);
    }

    STDMETHOD(SetRenderState)(THIS_ D3DRENDERSTATETYPE State, DWORD Value) {
        return this->original->SetRenderState(State, Value);
    }

    STDMETHOD(GetRenderState)(THIS_ D3DRENDERSTATETYPE State, DWORD* pValue) {
        return this->original->GetRenderState(State, pValue);
    }

    STDMETHOD(CreateStateBlock)(THIS_ D3DSTATEBLOCKTYPE Type, IDirect3DStateBlock9** ppSB) {
        return this->original->CreateStateBlock(Type, ppSB);
    }

    STDMETHOD(BeginStateBlock)(THIS) {
        return this->original->BeginStateBlock();
    }

    STDMETHOD(EndStateBlock)(THIS_ IDirect3DStateBlock9** ppSB) {
        return this->original->EndStateBlock(ppSB);
    }

    STDMETHOD(SetClipStatus)(THIS_ CONST D3DCLIPSTATUS9* pClipStatus) {
        return this->original->SetClipStatus(pClipStatus);
    }

    STDMETHOD(GetClipStatus)(THIS_ D3DCLIPSTATUS9* pClipStatus) {
        return this->original->GetClipStatus(pClipStatus);
    }

    STDMETHOD(GetTexture)(THIS_ DWORD Stage, IDirect3DBaseTexture9** ppTexture) {
        return this->original->GetTexture(Stage, ppTexture);
    }

    STDMETHOD(SetTexture)(THIS_ DWORD Stage, IDirect3DBaseTexture9* pTexture) {
        return this->original->SetTexture(Stage, pTexture);
    }

    STDMETHOD(GetTextureStageState)(THIS_ DWORD Stage, D3DTEXTURESTAGESTATETYPE Type, DWORD* pValue) {
        return this->original->GetTextureStageState(Stage, Type, pValue);
    }

    STDMETHOD(SetTextureStageState)(THIS_ DWORD Stage, D3DTEXTURESTAGESTATETYPE Type, DWORD Value) {
        return this->original->SetTextureStageState(Stage, Type, Value);
    }

    STDMETHOD(GetSamplerState)(THIS_ DWORD Sampler, D3DSAMPLERSTATETYPE Type, DWORD* pValue) {
        return this->original->GetSamplerState(Sampler, Type, pValue);
    }

    STDMETHOD(SetSamplerState)(THIS_ DWORD Sampler, D3DSAMPLERSTATETYPE Type, DWORD Value) {
        return this->original->SetSamplerState(Sampler, Type, Value);
    }

    STDMETHOD(ValidateDevice)(THIS_ DWORD* pNumPasses) {
        return this->original->ValidateDevice(pNumPasses);
    }

    STDMETHOD(SetPaletteEntries)(THIS_ UINT PaletteNumber, CONST PALETTEENTRY* pEntries) {
        return this->original->SetPaletteEntries(PaletteNumber, pEntries);
    }

    STDMETHOD(GetPaletteEntries)(THIS_ UINT PaletteNumber, PALETTEENTRY* pEntries) {
        return this->original->GetPaletteEntries(PaletteNumber, pEntries);
    }

    STDMETHOD(SetCurrentTexturePalette)(THIS_ UINT PaletteNumber) {
        return this->original->SetCurrentTexturePalette(PaletteNumber);
    }

    STDMETHOD(GetCurrentTexturePalette)(THIS_ UINT* PaletteNumber) {
        return this->original->GetCurrentTexturePalette(PaletteNumber);
    }

    STDMETHOD(SetScissorRect)(THIS_ CONST RECT* pRect) {
        return this->original->SetScissorRect(pRect);
    }

    STDMETHOD(GetScissorRect)(THIS_ RECT* pRect) {
        return this->original->GetScissorRect(pRect);
    }

    STDMETHOD(SetSoftwareVertexProcessing)(THIS_ BOOL bSoftware) {
        return this->original->SetSoftwareVertexProcessing(bSoftware);
    }

    STDMETHOD_(BOOL, GetSoftwareVertexProcessing)(THIS) {
        return this->original->GetSoftwareVertexProcessing();
    }

    STDMETHOD(SetNPatchMode)(THIS_ float nSegments) {
        return this->original->SetNPatchMode(nSegments);
    }

    STDMETHOD_(float, GetNPatchMode)(THIS) {
        return this->original->GetNPatchMode();
    }

    STDMETHOD(DrawPrimitive)(THIS_ D3DPRIMITIVETYPE PrimitiveType, UINT StartVertex, UINT PrimitiveCount) {
        return this->original->DrawPrimitive(PrimitiveType, StartVertex, PrimitiveCount);
    }

    STDMETHOD(DrawIndexedPrimitive)(THIS_ D3DPRIMITIVETYPE PrimitiveType, INT BaseVertexIndex, UINT MinVertexIndex, UINT NumVertices, UINT startIndex, UINT primCount) {
        return this->original->DrawIndexedPrimitive(PrimitiveType, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
    }

    STDMETHOD(DrawPrimitiveUP)(THIS_ D3DPRIMITIVETYPE PrimitiveType, UINT PrimitiveCount, CONST void* pVertexStreamZeroData, UINT VertexStreamZeroStride) {
        return this->original->DrawPrimitiveUP(PrimitiveType, PrimitiveCount, pVertexStreamZeroData, VertexStreamZeroStride);
    }

    STDMETHOD(DrawIndexedPrimitiveUP)(THIS_ D3DPRIMITIVETYPE PrimitiveType, UINT MinVertexIndex, UINT NumVertices, UINT PrimitiveCount, CONST void* pIndexData, D3DFORMAT IndexDataFormat, CONST void* pVertexStreamZeroData, UINT VertexStreamZeroStride) {
        return this->original->DrawIndexedPrimitiveUP(PrimitiveType, MinVertexIndex, NumVertices, PrimitiveCount, pIndexData, IndexDataFormat, pVertexStreamZeroData, VertexStreamZeroStride);
    }

    STDMETHOD(ProcessVertices)(THIS_ UINT SrcStartIndex, UINT DestIndex, UINT VertexCount, IDirect3DVertexBuffer9* pDestBuffer, IDirect3DVertexDeclaration9* pVertexDecl, DWORD Flags) {
        return this->original->ProcessVertices(SrcStartIndex, DestIndex, VertexCount, pDestBuffer, pVertexDecl, Flags);
    }

    STDMETHOD(CreateVertexDeclaration)(THIS_ CONST D3DVERTEXELEMENT9* pVertexElements, IDirect3DVertexDeclaration9** ppDecl) {
        return this->original->CreateVertexDeclaration(pVertexElements, ppDecl);
    }

    STDMETHOD(SetVertexDeclaration)(THIS_ IDirect3DVertexDeclaration9* pDecl) {
        return this->original->SetVertexDeclaration(pDecl);
    }

    STDMETHOD(GetVertexDeclaration)(THIS_ IDirect3DVertexDeclaration9** ppDecl) {
        return this->original->GetVertexDeclaration(ppDecl);
    }

    STDMETHOD(SetFVF)(THIS_ DWORD FVF) {
        return this->original->SetFVF(FVF);
    }

    STDMETHOD(GetFVF)(THIS_ DWORD* pFVF) {
        return this->original->GetFVF(pFVF);
    }

    STDMETHOD(CreateVertexShader)(THIS_ CONST DWORD* pFunction, IDirect3DVertexShader9** ppShader) {
        return this->original->CreateVertexShader(pFunction, ppShader);
    }

    STDMETHOD(SetVertexShader)(THIS_ IDirect3DVertexShader9* pShader) {
        return this->original->SetVertexShader(pShader);
    }

    STDMETHOD(GetVertexShader)(THIS_ IDirect3DVertexShader9** ppShader) {
        return this->original->GetVertexShader(ppShader);
    }

    STDMETHOD(SetVertexShaderConstantF)(THIS_ UINT StartRegister, CONST float* pConstantData, UINT Vector4fCount) {
        return this->original->SetVertexShaderConstantF(StartRegister, pConstantData, Vector4fCount);
    }

    STDMETHOD(GetVertexShaderConstantF)(THIS_ UINT StartRegister, float* pConstantData, UINT Vector4fCount) {
        return this->original->GetVertexShaderConstantF(StartRegister, pConstantData, Vector4fCount);
    }

    STDMETHOD(SetVertexShaderConstantI)(THIS_ UINT StartRegister, CONST int* pConstantData, UINT Vector4iCount) {
        return this->original->SetVertexShaderConstantI(StartRegister, pConstantData, Vector4iCount);
    }

    STDMETHOD(GetVertexShaderConstantI)(THIS_ UINT StartRegister, int* pConstantData, UINT Vector4iCount) {
        return this->original->GetVertexShaderConstantI(StartRegister, pConstantData, Vector4iCount);
    }

    STDMETHOD(SetVertexShaderConstantB)(THIS_ UINT StartRegister, CONST BOOL* pConstantData, UINT  BoolCount) {
        return this->original->SetVertexShaderConstantB(StartRegister, pConstantData, BoolCount);
    }

    STDMETHOD(GetVertexShaderConstantB)(THIS_ UINT StartRegister, BOOL* pConstantData, UINT BoolCount) {
        return this->original->GetVertexShaderConstantB(StartRegister, pConstantData, BoolCount);
    }

    STDMETHOD(SetStreamSource)(THIS_ UINT StreamNumber, IDirect3DVertexBuffer9* pStreamData, UINT OffsetInBytes, UINT Stride) {
        return this->original->SetStreamSource(StreamNumber, pStreamData, OffsetInBytes, Stride);
    }

    STDMETHOD(GetStreamSource)(THIS_ UINT StreamNumber, IDirect3DVertexBuffer9** ppStreamData, UINT* OffsetInBytes, UINT* pStride) {
        return this->original->GetStreamSource(StreamNumber, ppStreamData, OffsetInBytes, pStride);
    }

    STDMETHOD(SetStreamSourceFreq)(THIS_ UINT StreamNumber, UINT Divider) {
        return this->original->SetStreamSourceFreq(StreamNumber, Divider);
    }

    STDMETHOD(GetStreamSourceFreq)(THIS_ UINT StreamNumber, UINT* Divider) {
        return this->original->GetStreamSourceFreq(StreamNumber, Divider);
    }

    STDMETHOD(SetIndices)(THIS_ IDirect3DIndexBuffer9* pIndexData) {
        return this->original->SetIndices(pIndexData);
    }

    STDMETHOD(GetIndices)(THIS_ IDirect3DIndexBuffer9** ppIndexData) {
        return this->original->GetIndices(ppIndexData);
    }

    STDMETHOD(CreatePixelShader)(THIS_ CONST DWORD* pFunction, IDirect3DPixelShader9** ppShader) {
        return this->original->CreatePixelShader(pFunction, ppShader);
    }

    STDMETHOD(SetPixelShader)(THIS_ IDirect3DPixelShader9* pShader) {
        return this->original->SetPixelShader(pShader);
    }

    STDMETHOD(GetPixelShader)(THIS_ IDirect3DPixelShader9** ppShader) {
        return this->original->GetPixelShader(ppShader);
    }

    STDMETHOD(SetPixelShaderConstantF)(THIS_ UINT StartRegister, CONST float* pConstantData, UINT Vector4fCount) {
        return this->original->SetPixelShaderConstantF(StartRegister, pConstantData, Vector4fCount);
    }

    STDMETHOD(GetPixelShaderConstantF)(THIS_ UINT StartRegister, float* pConstantData, UINT Vector4fCount) {
        return this->original->GetPixelShaderConstantF(StartRegister, pConstantData, Vector4fCount);
    }

    STDMETHOD(SetPixelShaderConstantI)(THIS_ UINT StartRegister, CONST int* pConstantData, UINT Vector4iCount) {
        return this->original->SetPixelShaderConstantI(StartRegister, pConstantData, Vector4iCount);
    }

    STDMETHOD(GetPixelShaderConstantI)(THIS_ UINT StartRegister, int* pConstantData, UINT Vector4iCount) {
        return this->original->GetPixelShaderConstantI(StartRegister, pConstantData, Vector4iCount);
    }

    STDMETHOD(SetPixelShaderConstantB)(THIS_ UINT StartRegister, CONST BOOL* pConstantData, UINT  BoolCount) {
        return this->original->SetPixelShaderConstantB(StartRegister, pConstantData, BoolCount);
    }

    STDMETHOD(GetPixelShaderConstantB)(THIS_ UINT StartRegister, BOOL* pConstantData, UINT BoolCount) {
        return this->original->GetPixelShaderConstantB(StartRegister, pConstantData, BoolCount);
    }

    STDMETHOD(DrawRectPatch)(THIS_ UINT Handle, CONST float* pNumSegs, CONST D3DRECTPATCH_INFO* pRectPatchInfo) {
        return this->original->DrawRectPatch(Handle, pNumSegs, pRectPatchInfo);
    }

    STDMETHOD(DrawTriPatch)(THIS_ UINT Handle, CONST float* pNumSegs, CONST D3DTRIPATCH_INFO* pTriPatchInfo) {
        return this->original->DrawTriPatch(Handle, pNumSegs, pTriPatchInfo);
    }

    STDMETHOD(DeletePatch)(THIS_ UINT Handle) {
        return this->original->DeletePatch(Handle);
    }

    STDMETHOD(CreateQuery)(THIS_ D3DQUERYTYPE Type, IDirect3DQuery9** ppQuery) {
        return this->original->CreateQuery(Type, ppQuery);
    }


    /*** Helper information ***/
    D3DDEVICE_CREATION_PARAMETERS CreationParameters;
    D3DPRESENT_PARAMETERS PresentParameters;
    D3DDISPLAYMODE DisplayMode;
    D3DCAPS9 Caps;

    UINT AvailableTextureMem;
    UINT SwapChains;
    UINT Textures;
    UINT VertexBuffers;
    UINT IndexBuffers;
    UINT VertexShaders;
    UINT PixelShaders;

    D3DVIEWPORT9 Viewport;
    D3DMATRIX ProjectionMatrix;
    D3DMATRIX ViewMatrix;
    D3DMATRIX WorldMatrix;
    D3DMATRIX TextureMatrices[8];

    DWORD FVF;
    UINT VertexSize;
    DWORD VertexShaderVersion;
    DWORD PixelShaderVersion;
    BOOL SoftwareVertexProcessing;

    D3DMATERIAL9 Material;
    D3DLIGHT9 Lights[16];
    BOOL LightsEnabled[16];

    D3DGAMMARAMP GammaRamp;
    RECT ScissorRect;
    BOOL DialogBoxMode;
};

