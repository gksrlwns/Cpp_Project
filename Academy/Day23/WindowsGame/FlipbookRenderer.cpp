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

	::TransparentBlt(hdc,
		this->_owner->GetPos().x - _flipbookInfo.Size.x / 2,
		this->_owner->GetPos().y - _flipbookInfo.Size.y / 2,
		_flipbookInfo.Size.y,
		_flipbookInfo.Size.y,
		_flipbookInfo.Texture->GetDC(),
		_info.Index * _flipbookInfo.Size.x,
		_flipbookInfo.Line * _flipbookInfo.Size.y,
		_flipbookInfo.Size.x,
		_flipbookInfo.Size.y,
		_flipbookInfo.Texture->GetTransparent()
	);

}
void FlipbookRenderer::Update()
{
	Super::Update();

	FlipbookRendererInfo info = _info;

	info.SumTime += Time->GetDeltaTime();

	if (_flipbookInfo.Duration <= info.SumTime)
	{
		// 연출시간 초과
		if (_flipbookInfo.Loop == true)
		{
			info.SumTime -= _flipbookInfo.Duration;
		}
		else
		{
			info.Index = _flipbookInfo.End;
		}
	}
	else
	{
		//연출시간중에는 계산을 해준다.
		int frameAmount = _flipbookInfo.End - _flipbookInfo.Start + 1;

		float frameTime = _flipbookInfo.Duration / static_cast<float>(frameAmount);

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