#include "pch.h"
#include "Tilemap.h"
#include "GameObject.h"
void  Tilemap::LoadFile(const wstring& path)
{
	//회사마다 보통 File IO 만들어둠
	// 이 코드는 크게 참고하지 않아도 됨
	wifstream ifs;
	ifs.open(path);
	try
	{
		ifs >> _mapSize.x;
		ifs >> _mapSize.y;

		_tiles = vector<vector<Tile>>(_mapSize.y, vector<Tile>(_mapSize.x));

		for (int y = 0; y < _mapSize.y; y++)
		{
			wstring line;
			ifs >> line;
			for (int x = 0; x < _mapSize.x; x++)
			{
				//두글자 씩 끊어서 저장
				int value10 = line[x * 2] - L'0'; // 0 ~ 9
				int value1 = line[x * 2 + 1] - L'0';// 1의 자리

				_tiles[y][x].Value = value10 * 10 + value1;
			}
		}
		ifs.close();
	}
	catch (exception* ex)
	{

	}
}
void Tilemap::Render(HDC hdc, int x, int y)
{
	//그림을 그릴 때,
	//_tiles[y][x]에 따라서 그림을 그리면 되는데
	//Tile Value에 따라서 어떤 스프라이트를 써야하는지는 정보가 없음

}