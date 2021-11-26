#include "pch.h"
#include "MyIDirect3DDevice9.h"

MyIDirect3DDevice9::MyIDirect3DDevice9(IDirect3DDevice9 *original)
{
    this->original = original;

    this->CreationParameters = this->original->CreationParameters;
    this->PresentParameters = this->original->PresentParameters;
    this->DisplayMode = this->original->DisplayMode;
    this->Caps = this->original->Caps;

    this->AvailableTextureMem = this->original->AvailableTextureMem;
    this->SwapChains = this->original->SwapChains;
    this->Textures = this->original->Textures;
    this->VertexBuffers = this->original->VertexBuffers;
    this->IndexBuffers = this->original->IndexBuffers;
    this->VertexShaders = this->original->VertexShaders;
    this->PixelShaders = this->original->PixelShaders;

    this->Viewport = this->original->Viewport;
    this->ProjectionMatrix = this->original->ProjectionMatrix;
    this->ViewMatrix = this->original->ViewMatrix;
    this->WorldMatrix = this->original->WorldMatrix;

    for (int i = 0; i < 8; i++) {
        this->TextureMatrices[i] = this->original->TextureMatrices[i];
    }
    //memcpy_s(this->TextureMatrices, sizeof(this->TextureMatrices), this->original->TextureMatrices, sizeof(this->original->TextureMatrices));

    this->FVF = this->original->FVF;
    this->VertexSize = this->original->VertexSize;
    this->VertexShaderVersion = this->original->VertexShaderVersion;
    this->PixelShaderVersion = this->original->PixelShaderVersion;
    this->SoftwareVertexProcessing = this->original->SoftwareVertexProcessing;

    this->Material = this->original->Material;

    for (int i = 0; i < 16; i++) {
        this->Lights[i] = this->original->Lights[i];
        this->LightsEnabled[i] = this->original->LightsEnabled[i];
    }
    //memcpy_s(this->Lights, sizeof(this->Lights), this->original->Lights, sizeof(this->original->Lights));
    //memcpy_s(this->LightsEnabled, sizeof(this->LightsEnabled), this->original->LightsEnabled, sizeof(this->original->LightsEnabled));

    this->GammaRamp = this->original->GammaRamp;
    this->ScissorRect = this->original->ScissorRect;
    this->DialogBoxMode = this->original->DialogBoxMode;
}

/*** IUnknown methods ***/
HRESULT MyIDirect3DDevice9::QueryInterface(REFIID riid, void **ppvObj)
{
    return this->original->QueryInterface(riid, ppvObj);
}

ULONG MyIDirect3DDevice9::AddRef(THIS)
{
    return this->original->AddRef();
}

ULONG MyIDirect3DDevice9::Release(THIS)
{
    return this->original->Release();
}

/*** IDirect3DDevice9 methods ***/
HRESULT MyIDirect3DDevice9::TestCooperativeLevel(THIS)
{
    return this->original->TestCooperativeLevel();
}

UINT MyIDirect3DDevice9::GetAvailableTextureMem(THIS)
{
    return this->original->GetAvailableTextureMem();
}

HRESULT MyIDirect3DDevice9::EvictManagedResources(THIS)
{
    return this->original->EvictManagedResources();
}

HRESULT MyIDirect3DDevice9::GetDirect3D(IDirect3D9 **ppD3D9)
{
    return this->original->GetDirect3D(ppD3D9);
}

HRESULT MyIDirect3DDevice9::GetDeviceCaps(D3DCAPS9 *pCaps)
{
    return this->original->GetDeviceCaps(pCaps);
}

HRESULT MyIDirect3DDevice9::GetDisplayMode(UINT iSwapChain, D3DDISPLAYMODE *pMode)
{
    return this->original->GetDisplayMode(iSwapChain, pMode);
}

HRESULT MyIDirect3DDevice9::GetCreationParameters(D3DDEVICE_CREATION_PARAMETERS *pParameters)
{
    return this->original->GetCreationParameters(pParameters);
}

HRESULT MyIDirect3DDevice9::SetCursorProperties(UINT XHotSpot, UINT YHotSpot, IDirect3DSurface9 *pCursorBitmap)
{
    return this->original->SetCursorProperties(XHotSpot, YHotSpot, pCursorBitmap);
}

void MyIDirect3DDevice9::SetCursorPosition(int X, int Y, DWORD Flags)
{
    return this->original->SetCursorPosition(X, Y, Flags);
}

BOOL MyIDirect3DDevice9::ShowCursor(BOOL bShow)
{
    return this->original->ShowCursor(bShow);
}

HRESULT MyIDirect3DDevice9::CreateAdditionalSwapChain(D3DPRESENT_PARAMETERS *pPresentationParameters, IDirect3DSwapChain9 **pSwapChain)
{
    return this->original->CreateAdditionalSwapChain(pPresentationParameters, pSwapChain);
}

HRESULT MyIDirect3DDevice9::GetSwapChain(UINT iSwapChain, IDirect3DSwapChain9 **pSwapChain)
{
    return this->original->GetSwapChain(iSwapChain, pSwapChain);
}

UINT MyIDirect3DDevice9::GetNumberOfSwapChains(THIS)
{
    return this->original->GetNumberOfSwapChains();
}

HRESULT MyIDirect3DDevice9::Reset(D3DPRESENT_PARAMETERS *pPresentationParameters)
{
    return this->original->Reset(pPresentationParameters);
}

HRESULT MyIDirect3DDevice9::Present(CONST RECT *pSourceRect, CONST RECT *pDestRect, HWND hDestWindowOverride, CONST RGNDATA *pDirtyRegion)
{
    return this->original->Present(pSourceRect, pDestRect, hDestWindowOverride, pDirtyRegion);
}

HRESULT MyIDirect3DDevice9::GetBackBuffer(UINT iSwapChain, UINT iBackBuffer, D3DBACKBUFFER_TYPE Type, IDirect3DSurface9 **ppBackBuffer)
{
    return this->original->GetBackBuffer(iSwapChain, iBackBuffer, Type, ppBackBuffer);
}

HRESULT MyIDirect3DDevice9::GetRasterStatus(UINT iSwapChain, D3DRASTER_STATUS *pRasterStatus)
{
    return this->original->GetRasterStatus(iSwapChain, pRasterStatus);
}

HRESULT MyIDirect3DDevice9::SetDialogBoxMode(BOOL bEnableDialogs)
{
    return this->original->SetDialogBoxMode(bEnableDialogs);
}

void MyIDirect3DDevice9::SetGammaRamp(UINT iSwapChain, DWORD Flags, CONST D3DGAMMARAMP *pRamp)
{
    return this->original->SetGammaRamp(iSwapChain, Flags, pRamp);
}

void MyIDirect3DDevice9::GetGammaRamp(UINT iSwapChain, D3DGAMMARAMP *pRamp)
{
    return this->original->GetGammaRamp(iSwapChain, pRamp);
}

HRESULT MyIDirect3DDevice9::CreateTexture(UINT Width, UINT Height, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DTexture9 **ppTexture, HANDLE *pSharedHandle)
{
    return this->original->CreateTexture(Width, Height, Levels, Usage, Format, Pool, ppTexture, pSharedHandle);
}

HRESULT MyIDirect3DDevice9::CreateVolumeTexture(UINT Width, UINT Height, UINT Depth, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DVolumeTexture9 **ppVolumeTexture, HANDLE *pSharedHandle)
{
    return this->original->CreateVolumeTexture(Width, Height, Depth, Levels, Usage, Format, Pool, ppVolumeTexture, pSharedHandle);
}

HRESULT MyIDirect3DDevice9::CreateCubeTexture(UINT EdgeLength, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DCubeTexture9 **ppCubeTexture, HANDLE *pSharedHandle)
{
    return this->original->CreateCubeTexture(EdgeLength, Levels, Usage, Format, Pool, ppCubeTexture, pSharedHandle);
}

HRESULT MyIDirect3DDevice9::CreateVertexBuffer(UINT Length, DWORD Usage, DWORD FVF, D3DPOOL Pool, IDirect3DVertexBuffer9 **ppVertexBuffer, HANDLE *pSharedHandle)
{
    return this->original->CreateVertexBuffer(Length, Usage, FVF, Pool, ppVertexBuffer, pSharedHandle);
}

HRESULT MyIDirect3DDevice9::CreateIndexBuffer(UINT Length, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DIndexBuffer9 **ppIndexBuffer, HANDLE *pSharedHandle)
{
    return this->original->CreateIndexBuffer(Length, Usage, Format, Pool, ppIndexBuffer, pSharedHandle);
}

HRESULT MyIDirect3DDevice9::CreateRenderTarget(UINT Width, UINT Height, D3DFORMAT Format, D3DMULTISAMPLE_TYPE MultiSample, DWORD MultisampleQuality, BOOL Lockable, IDirect3DSurface9 **ppSurface, HANDLE *pSharedHandle)
{
    return this->original->CreateRenderTarget(Width, Height, Format, MultiSample, MultisampleQuality, Lockable, ppSurface, pSharedHandle);
}

HRESULT MyIDirect3DDevice9::CreateDepthStencilSurface(UINT Width, UINT Height, D3DFORMAT Format, D3DMULTISAMPLE_TYPE MultiSample, DWORD MultisampleQuality, BOOL Discard, IDirect3DSurface9 **ppSurface, HANDLE *pSharedHandle)
{
    return this->original->CreateDepthStencilSurface(Width, Height, Format, MultiSample, MultisampleQuality, Discard, ppSurface, pSharedHandle);
}

HRESULT MyIDirect3DDevice9::UpdateSurface(IDirect3DSurface9 *pSourceSurface, CONST RECT *pSourceRect, IDirect3DSurface9 *pDestinationSurface, CONST POINT *pDestPoint)
{
    return this->original->UpdateSurface(pSourceSurface, pSourceRect, pDestinationSurface, pDestPoint);
}

HRESULT MyIDirect3DDevice9::UpdateTexture(IDirect3DBaseTexture9 *pSourceTexture, IDirect3DBaseTexture9 *pDestinationTexture)
{
    return this->original->UpdateTexture(pSourceTexture, pDestinationTexture);
}

HRESULT MyIDirect3DDevice9::GetRenderTargetData(IDirect3DSurface9 *pRenderTarget, IDirect3DSurface9 *pDestSurface)
{
    return this->original->GetRenderTargetData(pRenderTarget, pDestSurface);
}

HRESULT MyIDirect3DDevice9::GetFrontBufferData(UINT iSwapChain, IDirect3DSurface9 *pDestSurface)
{
    return this->original->GetFrontBufferData(iSwapChain, pDestSurface);
}

HRESULT MyIDirect3DDevice9::StretchRect(IDirect3DSurface9 *pSourceSurface, CONST RECT *pSourceRect, IDirect3DSurface9 *pDestSurface, CONST RECT *pDestRect, D3DTEXTUREFILTERTYPE Filter)
{
    return this->original->StretchRect(pSourceSurface, pSourceRect, pDestSurface, pDestRect, Filter);
}

HRESULT MyIDirect3DDevice9::ColorFill(IDirect3DSurface9 *pSurface, CONST RECT *pRect, D3DCOLOR color)
{
    return this->original->ColorFill(pSurface, pRect, color);
}

HRESULT MyIDirect3DDevice9::CreateOffscreenPlainSurface(UINT Width, UINT Height, D3DFORMAT Format, D3DPOOL Pool, IDirect3DSurface9 **ppSurface, HANDLE *pSharedHandle)
{
    return this->original->CreateOffscreenPlainSurface(Width, Height, Format, Pool, ppSurface, pSharedHandle);
}

HRESULT MyIDirect3DDevice9::SetRenderTarget(DWORD RenderTargetIndex, IDirect3DSurface9 *pRenderTarget)
{
    return this->original->SetRenderTarget(RenderTargetIndex, pRenderTarget);
}

HRESULT MyIDirect3DDevice9::GetRenderTarget(DWORD RenderTargetIndex, IDirect3DSurface9 **ppRenderTarget)
{
    return this->original->GetRenderTarget(RenderTargetIndex, ppRenderTarget);
}

HRESULT MyIDirect3DDevice9::SetDepthStencilSurface(IDirect3DSurface9 *pNewZStencil)
{
    return this->original->SetDepthStencilSurface(pNewZStencil);
}

HRESULT MyIDirect3DDevice9::GetDepthStencilSurface(IDirect3DSurface9 **ppZStencilSurface)
{
    return this->original->GetDepthStencilSurface(ppZStencilSurface);
}

HRESULT MyIDirect3DDevice9::BeginScene(THIS)
{
    return this->original->BeginScene();
}

HRESULT MyIDirect3DDevice9::EndScene(THIS)
{
    return this->original->EndScene();
}

HRESULT MyIDirect3DDevice9::Clear(DWORD Count, CONST D3DRECT *pRects, DWORD Flags, D3DCOLOR Color, float Z, DWORD Stencil)
{
    return this->original->Clear(Count, pRects, Flags, Color, Z, Stencil);
}

HRESULT MyIDirect3DDevice9::SetTransform(D3DTRANSFORMSTATETYPE State, CONST D3DMATRIX *pMatrix)
{
    return this->original->SetTransform(State, pMatrix);
}

HRESULT MyIDirect3DDevice9::GetTransform(D3DTRANSFORMSTATETYPE State, D3DMATRIX *pMatrix)
{
    return this->original->GetTransform(State, pMatrix);
}

HRESULT MyIDirect3DDevice9::MultiplyTransform(D3DTRANSFORMSTATETYPE State, CONST D3DMATRIX *pMatrix)
{
    return this->original->MultiplyTransform(State, pMatrix);
}

HRESULT MyIDirect3DDevice9::SetViewport(CONST D3DVIEWPORT9 *pViewport)
{
    return this->original->SetViewport(pViewport);
}

HRESULT MyIDirect3DDevice9::GetViewport(D3DVIEWPORT9 *pViewport)
{
    return this->original->GetViewport(pViewport);
}

HRESULT MyIDirect3DDevice9::SetMaterial(CONST D3DMATERIAL9 *pMaterial)
{
    return this->original->SetMaterial(pMaterial);
}

HRESULT MyIDirect3DDevice9::GetMaterial(D3DMATERIAL9 *pMaterial)
{
    return this->original->GetMaterial(pMaterial);
}

HRESULT MyIDirect3DDevice9::SetLight(DWORD Index, CONST D3DLIGHT9 *pLight)
{
    return this->original->SetLight(Index, pLight);
}

HRESULT MyIDirect3DDevice9::GetLight(DWORD Index, D3DLIGHT9 *pLight)
{
    return this->original->GetLight(Index, pLight);
}

HRESULT MyIDirect3DDevice9::LightEnable(DWORD Index, BOOL Enable)
{
    return this->original->LightEnable(Index, Enable);
}

HRESULT MyIDirect3DDevice9::GetLightEnable(DWORD Index, BOOL *pEnable)
{
    return this->original->GetLightEnable(Index, pEnable);
}

HRESULT MyIDirect3DDevice9::SetClipPlane(DWORD Index, CONST float *pPlane)
{
    return this->original->SetClipPlane(Index, pPlane);
}

HRESULT MyIDirect3DDevice9::GetClipPlane(DWORD Index, float *pPlane)
{
    return this->original->GetClipPlane(Index, pPlane);
}

HRESULT MyIDirect3DDevice9::SetRenderState(D3DRENDERSTATETYPE State, DWORD Value)
{
    return this->original->SetRenderState(State, Value);
}

HRESULT MyIDirect3DDevice9::GetRenderState(D3DRENDERSTATETYPE State, DWORD *pValue)
{
    return this->original->GetRenderState(State, pValue);
}

HRESULT MyIDirect3DDevice9::CreateStateBlock(D3DSTATEBLOCKTYPE Type, IDirect3DStateBlock9 **ppSB)
{
    return this->original->CreateStateBlock(Type, ppSB);
}

HRESULT MyIDirect3DDevice9::BeginStateBlock(THIS)
{
    return this->original->BeginStateBlock();
}

HRESULT MyIDirect3DDevice9::EndStateBlock(IDirect3DStateBlock9 **ppSB)
{
    return this->original->EndStateBlock(ppSB);
}

HRESULT MyIDirect3DDevice9::SetClipStatus(CONST D3DCLIPSTATUS9 *pClipStatus)
{
    return this->original->SetClipStatus(pClipStatus);
}

HRESULT MyIDirect3DDevice9::GetClipStatus(D3DCLIPSTATUS9 *pClipStatus)
{
    return this->original->GetClipStatus(pClipStatus);
}

HRESULT MyIDirect3DDevice9::GetTexture(DWORD Stage, IDirect3DBaseTexture9 **ppTexture)
{
    return this->original->GetTexture(Stage, ppTexture);
}

HRESULT MyIDirect3DDevice9::SetTexture(DWORD Stage, IDirect3DBaseTexture9 *pTexture)
{
    return this->original->SetTexture(Stage, pTexture);
}

HRESULT MyIDirect3DDevice9::GetTextureStageState(DWORD Stage, D3DTEXTURESTAGESTATETYPE Type, DWORD *pValue)
{
    return this->original->GetTextureStageState(Stage, Type, pValue);
}

HRESULT MyIDirect3DDevice9::SetTextureStageState(DWORD Stage, D3DTEXTURESTAGESTATETYPE Type, DWORD Value)
{
    return this->original->SetTextureStageState(Stage, Type, Value);
}

HRESULT MyIDirect3DDevice9::GetSamplerState(DWORD Sampler, D3DSAMPLERSTATETYPE Type, DWORD *pValue)
{
    return this->original->GetSamplerState(Sampler, Type, pValue);
}

HRESULT MyIDirect3DDevice9::SetSamplerState(DWORD Sampler, D3DSAMPLERSTATETYPE Type, DWORD Value)
{
    return this->original->SetSamplerState(Sampler, Type, Value);
}

HRESULT MyIDirect3DDevice9::ValidateDevice(DWORD *pNumPasses)
{
    return this->original->ValidateDevice(pNumPasses);
}

HRESULT MyIDirect3DDevice9::SetPaletteEntries(UINT PaletteNumber, CONST PALETTEENTRY *pEntries)
{
    return this->original->SetPaletteEntries(PaletteNumber, pEntries);
}

HRESULT MyIDirect3DDevice9::GetPaletteEntries(UINT PaletteNumber, PALETTEENTRY *pEntries)
{
    return this->original->GetPaletteEntries(PaletteNumber, pEntries);
}

HRESULT MyIDirect3DDevice9::SetCurrentTexturePalette(UINT PaletteNumber)
{
    return this->original->SetCurrentTexturePalette(PaletteNumber);
}

HRESULT MyIDirect3DDevice9::GetCurrentTexturePalette(UINT *PaletteNumber)
{
    return this->original->GetCurrentTexturePalette(PaletteNumber);
}

HRESULT MyIDirect3DDevice9::SetScissorRect(CONST RECT *pRect)
{
    return this->original->SetScissorRect(pRect);
}

HRESULT MyIDirect3DDevice9::GetScissorRect(RECT *pRect)
{
    return this->original->GetScissorRect(pRect);
}

HRESULT MyIDirect3DDevice9::SetSoftwareVertexProcessing(BOOL bSoftware)
{
    return this->original->SetSoftwareVertexProcessing(bSoftware);
}

BOOL MyIDirect3DDevice9::GetSoftwareVertexProcessing(THIS)
{
    return this->original->GetSoftwareVertexProcessing();
}

HRESULT MyIDirect3DDevice9::SetNPatchMode(float nSegments)
{
    return this->original->SetNPatchMode(nSegments);
}

float MyIDirect3DDevice9::GetNPatchMode(THIS)
{
    return this->original->GetNPatchMode();
}

HRESULT MyIDirect3DDevice9::DrawPrimitive(D3DPRIMITIVETYPE PrimitiveType, UINT StartVertex, UINT PrimitiveCount)
{
    return this->original->DrawPrimitive(PrimitiveType, StartVertex, PrimitiveCount);
}

HRESULT MyIDirect3DDevice9::DrawIndexedPrimitive(D3DPRIMITIVETYPE PrimitiveType, INT BaseVertexIndex, UINT MinVertexIndex, UINT NumVertices, UINT startIndex, UINT primCount)
{
    return this->original->DrawIndexedPrimitive(PrimitiveType, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
}

HRESULT MyIDirect3DDevice9::DrawPrimitiveUP(D3DPRIMITIVETYPE PrimitiveType, UINT PrimitiveCount, CONST void *pVertexStreamZeroData, UINT VertexStreamZeroStride)
{
    return this->original->DrawPrimitiveUP(PrimitiveType, PrimitiveCount, pVertexStreamZeroData, VertexStreamZeroStride);
}

HRESULT MyIDirect3DDevice9::DrawIndexedPrimitiveUP(D3DPRIMITIVETYPE PrimitiveType, UINT MinVertexIndex, UINT NumVertices, UINT PrimitiveCount, CONST void *pIndexData, D3DFORMAT IndexDataFormat, CONST void *pVertexStreamZeroData, UINT VertexStreamZeroStride)
{
    return this->original->DrawIndexedPrimitiveUP(PrimitiveType, MinVertexIndex, NumVertices, PrimitiveCount, pIndexData, IndexDataFormat, pVertexStreamZeroData, VertexStreamZeroStride);
}

HRESULT MyIDirect3DDevice9::ProcessVertices(UINT SrcStartIndex, UINT DestIndex, UINT VertexCount, IDirect3DVertexBuffer9 *pDestBuffer, IDirect3DVertexDeclaration9 *pVertexDecl, DWORD Flags)
{
    return this->original->ProcessVertices(SrcStartIndex, DestIndex, VertexCount, pDestBuffer, pVertexDecl, Flags);
}

HRESULT MyIDirect3DDevice9::CreateVertexDeclaration(CONST D3DVERTEXELEMENT9 *pVertexElements, IDirect3DVertexDeclaration9 **ppDecl)
{
    return this->original->CreateVertexDeclaration(pVertexElements, ppDecl);
}

HRESULT MyIDirect3DDevice9::SetVertexDeclaration(IDirect3DVertexDeclaration9 *pDecl)
{
    return this->original->SetVertexDeclaration(pDecl);
}

HRESULT MyIDirect3DDevice9::GetVertexDeclaration(IDirect3DVertexDeclaration9 **ppDecl)
{
    return this->original->GetVertexDeclaration(ppDecl);
}

HRESULT MyIDirect3DDevice9::SetFVF(DWORD FVF)
{
    return this->original->SetFVF(FVF);
}

HRESULT MyIDirect3DDevice9::GetFVF(DWORD *pFVF)
{
    return this->original->GetFVF(pFVF);
}

HRESULT MyIDirect3DDevice9::CreateVertexShader(CONST DWORD *pFunction, IDirect3DVertexShader9 **ppShader)
{
    return this->original->CreateVertexShader(pFunction, ppShader);
}

HRESULT MyIDirect3DDevice9::SetVertexShader(IDirect3DVertexShader9 *pShader)
{
    return this->original->SetVertexShader(pShader);
}

HRESULT MyIDirect3DDevice9::GetVertexShader(IDirect3DVertexShader9 **ppShader)
{
    return this->original->GetVertexShader(ppShader);
}

HRESULT MyIDirect3DDevice9::SetVertexShaderConstantF(UINT StartRegister, CONST float *pConstantData, UINT Vector4fCount)
{
    return this->original->SetVertexShaderConstantF(StartRegister, pConstantData, Vector4fCount);
}

HRESULT MyIDirect3DDevice9::GetVertexShaderConstantF(UINT StartRegister, float *pConstantData, UINT Vector4fCount)
{
    return this->original->GetVertexShaderConstantF(StartRegister, pConstantData, Vector4fCount);
}

HRESULT MyIDirect3DDevice9::SetVertexShaderConstantI(UINT StartRegister, CONST INT *pConstantData, UINT Vector4iCount)
{
    return this->original->SetVertexShaderConstantI(StartRegister, pConstantData, Vector4iCount);
}

HRESULT MyIDirect3DDevice9::GetVertexShaderConstantI(UINT StartRegister, INT *pConstantData, UINT Vector4iCount)
{
    return this->original->GetVertexShaderConstantI(StartRegister, pConstantData, Vector4iCount);
}

HRESULT MyIDirect3DDevice9::SetVertexShaderConstantB(UINT StartRegister, CONST BOOL *pConstantData, UINT BoolCount)
{
    return this->original->SetVertexShaderConstantB(StartRegister, pConstantData, BoolCount);
}

HRESULT MyIDirect3DDevice9::GetVertexShaderConstantB(UINT StartRegister, BOOL *pConstantData, UINT BoolCount)
{
    return this->original->GetVertexShaderConstantB(StartRegister, pConstantData, BoolCount);
}

HRESULT MyIDirect3DDevice9::SetStreamSource(UINT StreamNumber, IDirect3DVertexBuffer9 *pStreamData, UINT OffsetInBytes, UINT Stride)
{
    return this->original->SetStreamSource(StreamNumber, pStreamData, OffsetInBytes, Stride);
}

HRESULT MyIDirect3DDevice9::GetStreamSource(UINT StreamNumber, IDirect3DVertexBuffer9 **ppStreamData, UINT *OffsetInBytes, UINT *pStride)
{
    return this->original->GetStreamSource(StreamNumber, ppStreamData, OffsetInBytes, pStride);
}

HRESULT MyIDirect3DDevice9::SetStreamSourceFreq(UINT StreamNumber, UINT Divider)
{
    return this->original->SetStreamSourceFreq(StreamNumber, Divider);
}

HRESULT MyIDirect3DDevice9::GetStreamSourceFreq(UINT StreamNumber, UINT *Divider)
{
    return this->original->GetStreamSourceFreq(StreamNumber, Divider);
}

HRESULT MyIDirect3DDevice9::SetIndices(IDirect3DIndexBuffer9 *pIndexData)
{
    return this->original->SetIndices(pIndexData);
}

HRESULT MyIDirect3DDevice9::GetIndices(IDirect3DIndexBuffer9 **ppIndexData)
{
    return this->original->GetIndices(ppIndexData);
}

HRESULT MyIDirect3DDevice9::CreatePixelShader(CONST DWORD *pFunction, IDirect3DPixelShader9 **ppShader)
{
    return this->original->CreatePixelShader(pFunction, ppShader);
}

HRESULT MyIDirect3DDevice9::SetPixelShader(IDirect3DPixelShader9 *pShader)
{
    return this->original->SetPixelShader(pShader);
}

HRESULT MyIDirect3DDevice9::GetPixelShader(IDirect3DPixelShader9 **ppShader)
{
    return this->original->GetPixelShader(ppShader);
}

HRESULT MyIDirect3DDevice9::SetPixelShaderConstantF(UINT StartRegister, CONST float *pConstantData, UINT Vector4fCount)
{
    return this->original->SetPixelShaderConstantF(StartRegister, pConstantData, Vector4fCount);
}

HRESULT MyIDirect3DDevice9::GetPixelShaderConstantF(UINT StartRegister, float *pConstantData, UINT Vector4fCount)
{
    return this->original->GetPixelShaderConstantF(StartRegister, pConstantData, Vector4fCount);
}

HRESULT MyIDirect3DDevice9::SetPixelShaderConstantI(UINT StartRegister, CONST INT *pConstantData, UINT Vector4iCount)
{
    return this->original->SetPixelShaderConstantI(StartRegister, pConstantData, Vector4iCount);
}

HRESULT MyIDirect3DDevice9::GetPixelShaderConstantI(UINT StartRegister, INT *pConstantData, UINT Vector4iCount)
{
    return this->original->GetPixelShaderConstantI(StartRegister, pConstantData, Vector4iCount);
}

HRESULT MyIDirect3DDevice9::SetPixelShaderConstantB(UINT StartRegister, CONST BOOL *pConstantData, UINT  BoolCount)
{
    return this->original->SetPixelShaderConstantB(StartRegister, pConstantData, BoolCount);
}

HRESULT MyIDirect3DDevice9::GetPixelShaderConstantB(UINT StartRegister, BOOL *pConstantData, UINT BoolCount)
{
    return this->original->GetPixelShaderConstantB(StartRegister, pConstantData, BoolCount);
}

HRESULT MyIDirect3DDevice9::DrawRectPatch(UINT Handle, CONST float *pNumSegs, CONST D3DRECTPATCH_INFO *pRectPatchInfo)
{
    return this->original->DrawRectPatch(Handle, pNumSegs, pRectPatchInfo);
}

HRESULT MyIDirect3DDevice9::DrawTriPatch(UINT Handle, CONST float *pNumSegs, CONST D3DTRIPATCH_INFO *pTriPatchInfo)
{
    return this->original->DrawTriPatch(Handle, pNumSegs, pTriPatchInfo);
}

HRESULT MyIDirect3DDevice9::DeletePatch(UINT Handle)
{
    return this->original->DeletePatch(Handle);
}

HRESULT MyIDirect3DDevice9::CreateQuery(D3DQUERYTYPE Type, IDirect3DQuery9 **ppQuery)
{
    return this->original->CreateQuery(Type, ppQuery);
}
