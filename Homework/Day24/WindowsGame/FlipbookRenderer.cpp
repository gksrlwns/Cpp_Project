#include "pch.h"
#include "FlipbookRenderer.h"
#include "Texture.h"
#include "GameObject.h"

void FlipbookRenderer::Init()
{
	Super::Init();
}
void FlipbookRenderer::Render(HDC hdc)
{
	Super::Render(hdc);

	FlipbookInfo flipbookInfo = _flipbook->GetInfo();

	::TransparentBlt(hdc,
		this->_owner->GetPos().x - flipbookInfo.Size.x / 2,
		this->_owner->GetPos().y - flipbookInfo.Size.y / 2,
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
	_info = info;
	_flipbook = Resource->GetFlipbook(info.FlipbookKey);
}