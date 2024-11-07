#pragma once
using int8 = __int8;
using int16 = __int16;
using int32 = __int32;
using int64 = __int64;
using uint8 = unsigned __int8;
using uint16 = unsigned __int16;
using uint32 = unsigned __int32;
using uint64 = unsigned __int64;

#include "Vector2Int.h"

struct Node
{
	Vector2Int Pos;
	Vector2Int ParentPos;

	Node(Vector2Int pos, Vector2Int parentPos)
	{
		Pos = pos;
		ParentPos = parentPos;
	}
};