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


struct PQNode
{
	Vector2Int Pos;
	float Cost;

	PQNode(Vector2Int pos, float cost)
	{
		Pos = pos;
		Cost = cost;
	}

	bool operator< (const PQNode& other) const
	{
		return Cost < other.Cost;
	}

	bool operator> (const PQNode& other) const
	{
		return Cost > other.Cost;
	}
};


struct AstarNode
{
	Vector2Int Pos;
	float G;	// 내가 걸어온길
	float H;	// 남은 길

	AstarNode(Vector2Int pos, float g, float h)
	{
		Pos = pos;
		G = g;
		H = h;
	}

	float GetCost()	const
	{
		return G + H;
	}

	bool operator< (const AstarNode& other) const
	{
		return this->GetCost() < other.GetCost();
	}

	bool operator> (const AstarNode& other) const
	{
		return this->GetCost() > other.GetCost();
	}
};