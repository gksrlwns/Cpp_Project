﻿#include "pch.h"
#include "Player.h"
#include "Board.h"
#include <queue>
#include <stack>
void Player::Init(Board* board)
{
	_board = board;

	_pos = board->GetStartPos();

	//CalulatePath_RightHand();
	CalulatePath_BFS();
	//CalulatePath_DFS();

	_currentIndex = 0;
}
void Player::Update()
{
	//currentIndex를 하나씩증가시켜서 _path 위치로 변경
	_currentIndex++;

	if (_currentIndex < _path.size())
	{
		_pos = _path[_currentIndex];
	}

}

bool Player::CanGo(int x, int y)
{
	int size = _board->GetSize();

	if (false == (0 < x && x < size - 1))
	{
		return false;
	}

	if (false == (0 < y && y < size - 1))
	{
		return false;
	}

	TileType tile = _board->GetTileType(x, y);
	if (tile == TileType::Wall)
	{
		return false;
	}

	return true;
}


void Player::CalulatePath_RightHand()
{
	Vector2Int pos = _pos;
	_dir = EDir::Down;

	_path.clear();
	_path.push_back(pos);


	//목적지
	Vector2Int dest = _board->GetExitPos();

	Vector2Int front[4] =
	{
		Vector2Int(-1, 0)	// Left
		,Vector2Int(0, -1)	// Up
		,Vector2Int(1, 0)	// Right
		,Vector2Int(0, 1)	// Down
	};

	while (pos != dest)
	{
		//1. 현재 방향 기준으로, 오른쪽을 갈수있는지 확인
		int newDir = ((int)_dir + 1) % 4;
		if (CanGo(pos + front[newDir]))
		{
			// 오른쪽 방향으로 회전
			_dir = static_cast<EDir>(newDir);
			// 앞으로 한보 전진
			pos += front[newDir];

			//기록
			_path.push_back(pos);
		}
		//2. 내 현재 방향으로는 갈수있는지 체크
		else if (CanGo(pos + front[(int)_dir]))
		{
			// 앞으로 한보 전진
			pos += front[(int)_dir];

			//기록
			_path.push_back(pos);
		}
		else
		{
			// 왼쪽으로 회전
			int leftSideDir = ((int)_dir + 3) % 4;
			_dir = static_cast<EDir>(leftSideDir);
		}

	}
}

void Player::CalulatePath_BFS()
{
	Vector2Int pos = _pos;
	_dir = EDir::Down;

	_path.clear();
	_path.push_back(pos);

	//목적지
	Vector2Int dest = _board->GetExitPos();

	int frontSize = 8;
	Vector2Int front[8] =
	{
		Vector2Int(-1, 0)	// Left
		,Vector2Int(0, -1)	// Up
		,Vector2Int(1, 0)	// Right
		,Vector2Int(0, 1)	// Down
		,Vector2Int(-1, 1)
		,Vector2Int(-1, -1)
		,Vector2Int(1, 1)
		,Vector2Int(1, -1)
	};

	int size = _board->GetSize();
	vector<vector<bool>> visited = vector<vector<bool>>(size, vector<bool>(size, false));
	vector<vector<Vector2Int>> parents = vector<vector<Vector2Int>>(size, vector<Vector2Int>(size, Vector2Int(-1, -1)));
	queue<Node> q;
	q.push(Node(pos, Vector2Int(-1, -1)));

	while (false == q.empty())
	{
		// 현재 좌표를 큐에서 하나 가져온다.
		Node currentNode = q.front();
		pos = currentNode.Pos;

		q.pop();

		// 현재 좌표를 이미 왔다고 체크해둔다.
		visited[pos.y][pos.x] = true;

		// 부모좌표 세팅해줍니다. (값이 넣어진 경우만)
		if (false == (currentNode.ParentPos.x == -1 && currentNode.ParentPos.y == -1))
		{
			parents[pos.y][pos.x] = currentNode.ParentPos;
		}

		if (pos == dest)
			break;

		//내가 갈수있는 길을 모두 큐에 담아둔다.
		for (int i = 0; i < frontSize; i++)
		{
			Vector2Int nextPos = pos + front[i];

			// 갈수있어도 이미 방문한 지역인지 확인
			if (visited[nextPos.y][nextPos.x] == true)
				continue;

			// 갈수있는 지역인지 확인
			if (CanGo(nextPos) == false)
				continue;

			// 갈수잇는 지역이면 추가
			Node newNode = Node(nextPos, pos);
			q.push(newNode);
		}
	}

	pos = dest;
	_path.clear();
	while (true)
	{
		_path.push_back(pos);

		//시작점이 나올때까지 반복
		if (pos == _board->GetStartPos())
			break;

		pos = parents[pos.y][pos.x];
	}


	//// 뒤집는로직
	//for (int i = 0; i < _path.size() / 2; i++)
	//{
	//	int index1 = i;
	//	int index2 = _path.size() - 1 - i;

	//	//index1과 index2를 swap
	//	Vector2Int temp = _path[index1];
	//	_path[index1] = _path[index2];
	//	_path[index2] = temp;
	//}

	reverse(_path.begin(), _path.end());

}

void Player::CalulatePath_DFS()
{
	Vector2Int pos = _pos;
	_dir = EDir::Down;

	_path.clear();
	_path.push_back(pos);

	//목적지
	Vector2Int dest = _board->GetExitPos();

	int frontSize = 8;
	Vector2Int front[8] =
	{
		Vector2Int(-1, 0)	// Left
		,Vector2Int(0, -1)	// Up
		,Vector2Int(1, 0)	// Right
		,Vector2Int(0, 1)	// Down
		,Vector2Int(-1, 1)
		,Vector2Int(-1, -1)
		,Vector2Int(1, 1)
		,Vector2Int(1, -1)
	};

	int size = _board->GetSize();
	vector<vector<bool>> visited = vector<vector<bool>>(size, vector<bool>(size, false));
	vector<vector<Vector2Int>> parents = vector<vector<Vector2Int>>(size, vector<Vector2Int>(size, Vector2Int(-1, -1)));
	stack<Node> s;
	s.push(Node(pos, Vector2Int(-1, -1)));

	while (false == s.empty())
	{
		// 현재 좌표를 큐에서 하나 가져온다.
		Node currentNode = s.top();
		pos = currentNode.Pos;

		s.pop();

		// 현재 좌표를 이미 왔다고 체크해둔다.
		visited[pos.y][pos.x] = true;

		// 부모좌표 세팅해줍니다. (값이 넣어진 경우만)
		if (false == (currentNode.ParentPos.x == -1 && currentNode.ParentPos.y == -1))
		{
			parents[pos.y][pos.x] = currentNode.ParentPos;
		}

		if (pos == dest)
			break;

		//내가 갈수있는 길을 모두 큐에 담아둔다.
		for (int i = 0; i < frontSize; i++)
		{
			Vector2Int nextPos = pos + front[i];

			// 갈수있어도 이미 방문한 지역인지 확인
			if (visited[nextPos.y][nextPos.x] == true)
				continue;

			// 갈수있는 지역인지 확인
			if (CanGo(nextPos) == false)
				continue;

			// 갈수잇는 지역이면 추가
			Node newNode = Node(nextPos, pos);
			s.push(newNode);
		}
	}

	pos = dest;
	_path.clear();
	while (true)
	{
		_path.push_back(pos);

		//시작점이 나올때까지 반복
		if (pos == _board->GetStartPos())
			break;

		pos = parents[pos.y][pos.x];
	}


	//// 뒤집는로직
	//for (int i = 0; i < _path.size() / 2; i++)
	//{
	//	int index1 = i;
	//	int index2 = _path.size() - 1 - i;

	//	//index1과 index2를 swap
	//	Vector2Int temp = _path[index1];
	//	_path[index1] = _path[index2];
	//	_path[index2] = temp;
	//}

	reverse(_path.begin(), _path.end());

}