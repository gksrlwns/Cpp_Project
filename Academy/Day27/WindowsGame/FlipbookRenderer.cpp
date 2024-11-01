#include "pch.h"
#include "FlipbookRenderer.h"
#include "Texture.h"
#include "GameObject.h"
#include "Scene.h"

void FlipbookRenderer::Init()
{
	Super::Init();
}
void FlipbookRenderer::Render(HDC hdc)
{
	Super::Render(hdc);

	FlipbookInfo flipbookInfo = _flipbook->GetInfo();

	Vector2 cameraPos = CurrentScene->GetCameraPos();
	Vector2Int renderPos = {
		static_cast<int>(this->_owner->GetPos().x - flipbookInfo.Size.x / 2 - cameraPos.x),
		static_cast<int>(this->_owner->GetPos().y - flipbookInfo.Size.y / 2 - cameraPos.y)
	};


	::TransparentBlt(hdc,
		renderPos.x,
		renderPos.y,
		flipbookInfo.Size.y,
		flipbookInfo.Size.y,
		flipbookInfo.Texture->GetDC(),
		_info.Index * flipbookInfo.Size.x,
		flipbookInfo.Line * flipbookInfo.Size.y,
		flipbookInfo.Size.x,
		flipbookInfo.Size.y,
		flipbookInfo.Texture->GetTransparent()
	);

}
void FlipbookRenderer::Update()
{
	Super::Update();

	FlipbookRendererInfo info = _info;
	FlipbookInfo flipbookInfo = _flipbook->GetInfo();

	info.SumTime += Time->GetDeltaTime();

	if (flipbookInfo.Duration <= info.SumTime)
	{
		// 연출시간 초과
		if (flipbookInfo.Loop == true)
		{
			info.SumTime -= flipbookInfo.Duration;
		}
		else
		{
			info.Index = flipbookInfo.End;
		}
	}
	else
	{
		//연출시간중에는 계산을 해준다.
		int frameAmount = flipbookInfo.End - flipbookInfo.Start + 1;

		float frameTime = flipbookInfo.Duration / static_cast<float>(frameAmount);

		if (!EQUALS(frameTime, 0.0f))
		{
			info.Index = info.SumTime / frameTime;
		}
	}

	_info = info;
}
void FlipbookRenderer::Release()
{
	Super::Release();
}

void FlipbookRenderer::SetInfo(FlipbookRendererInfo info)
{
	_flipbook = Resource->GetFlipbook(info.FlipbookKey);
	_info = info;
	_info.LastIndex = _flipbook->GetInfo().End;
}