#pragma once
enum CenterRectDrawType
{
	DRAWTYPE_RECT,
	DRAWTYPE_ELIPSE
};
/// <summary>
/// RECT는 left, top, right, bottom를 사용하여,
/// 게임에서의 로직과는 적용하기 힘든 부분이 많아
/// 사각형을 [중심점 + 가로 세로]로 다루기 위해 만든 구조체
/// </summary>
struct CenterRect
{
	Vector2 pos = {0, 0};	//중심좌표
	float width = 0, height = 0;

	void Draw(HDC hdc, CenterRectDrawType drawType = DRAWTYPE_RECT, int brush = NULL_BRUSH);

	CenterRect(float x, float y, float width, float height);
	CenterRect(float x, float y);
	CenterRect();

	//CenterRect => RECT 구조체로 변경해주는 함수
	RECT ToRect();
	static CenterRect FromRect(RECT rc);
	static CenterRect MakeLTWH(float left, float top, float width, float height);
	float Top();
	float Bottom();
	float Left();
	float Right();
};