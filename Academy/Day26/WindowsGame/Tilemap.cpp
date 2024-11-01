#include "pch.h"
#include "Tilemap.h"
#include "GameObject.h"
void Tilemap::LoadFile(const wstring& path)
{
	// 회사마다 보통 FileIO를 만들어두거든요
	// 이코드는 크게 참고안하셔도돼요.

	wifstream ifs;
	ifs.open(path);
	try
	{
		ifs >> _mapSize.x;
		ifs >> _mapSize.y;

		_tiles = vector<vector<Tile>>(_mapSize.y, vector<Tile>(_mapSize.x));
		

		for (int y = 0; y < _mapSize.y; y++)
		{
			//한줄씩
			wstring line;
			ifs >> line;

			for (int x = 0; x < _mapSize.x; x++)
			{
				// 두글자씩 끊어서 저장했죠

				int value10 = line[x * 2] - L'0';	// 0 ~ 9 
				int value1 = line[x * 2 + 1] - L'0';

				_tiles[y][x].Value = value10 * 10 + value1;
			}
		}

		ifs.close();
	}
	catch (exception ex)
	{

		ifs.close();
	}

}

void Tilemap::Render(HDC hdc, int x, int y)
{
	// 그림을 그릴때,
	// _tiles[y][x] 에 따라서 그림을 그리면 되는데
	// Tile Value에 따라서 어떤 스프라이트를 써야하는지는 정보가 없습니다.
}