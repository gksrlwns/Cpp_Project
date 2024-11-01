#include "pch.h"
#include "Day17Box.h"
void Day17Box::Init()
{
	_body = CenterRect(500, 300, 300, 300);
}
void Day17Box::Render(HDC hdc)
{
	_body.Draw(hdc);
}
void Day17Box::Update()
{

}
void Day17Box::Release() 
{

}