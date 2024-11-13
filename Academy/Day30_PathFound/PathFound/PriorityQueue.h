#pragma once
#include <vector>
#include <assert.h>
using namespace std;

/// <summary>
/// T 에는 Operator<, > 필요.
/// </summary>
/// <typeparam name="T"></typeparam>
template <typename T>
class PriorityQueue
{
private:
	vector<T> _arr;

public:
	T& Peek()
	{
		assert(0 < _arr.size());
		return _arr[0];
	}

	bool Empty()
	{
		return _arr.size() == 0;
	}

	void Pop()
	{
		//1. 루트와 마지막노드를 스왑해준다.
		::swap(_arr[0], _arr[_arr.size() - 1]);
		
		//2. 스왑후에 마지막 노드를 삭제한다.
		_arr.pop_back();

		// 위에서부터 도장깨기
		int index = 0;

		// * validation check
		if (_arr.size() == 0)
			return;

		while (true)
		{
			//왼쪽인덱스가 없다면 (왼쪽 인덱스가 사이즈보다 더 크다면)
			//  -> 자식이 더이상 없다면
			if (_arr.size() - 1 < GetLeftChildIndex(index))
			{
				break;
			}

			// 1. 왼쪽노드만 있을때 
			//  -> 오른쪽 인덱스가 사이즈보다 더크면
			if (_arr.size() - 1 < GetRightChildIndex(index))
			{
				// 왼쪽이랑만 비교하면 됩니다.
				T& leftNode = _arr[GetLeftChildIndex(index)];

				//자식이 더크면
				if (_arr[index] < leftNode)
				{
					// 스왑을 해준다.
					::swap(leftNode, _arr[index]);

					// 인덱스를 그에 맞게 세팅해준다.
					index = GetLeftChildIndex(index);
				}
				else
				{
					break;
				}
			}
			// 2. 오른쪽노드도 있을때
			else
			{
				//왼쪽 노드와 오른쪽 노드중에 큰거랑 비교한다.
				T& leftNode = _arr[GetLeftChildIndex(index)];
				T& rightNode = _arr[GetRightChildIndex(index)];


				//자식이 더크면
				if (rightNode < leftNode)
				{
					if (_arr[index] < leftNode)
					{
						// 스왑을 해준다.
						::swap(leftNode, _arr[index]);

						// 인덱스를 그에 맞게 세팅해준다.
						index = GetLeftChildIndex(index);
					}
					else
					{
						break;
					}
				}
				else
				{
					if (_arr[index] < rightNode)
					{
						// 스왑을 해준다.
						::swap(rightNode, _arr[index]);

						// 인덱스를 그에 맞게 세팅해준다.
						index = GetRightChildIndex(index);
					}
					else
					{
						break;
					}
				}
			}

		}
	}


	void Push(T data)
	{
		// 1. 마지막에 데이터를 추가한다.
		_arr.push_back(data);

		// 아래서부터 위로 도장깨기를 한다.
		int index = _arr.size() - 1;

		while (true)
		{
			if (index <= 0) break;

			// 부모노드와 현재 노드를 비교한다.
			T& parentNode = _arr[GetParentIndex(index)];
			T& currentNode = _arr[index];

			// 부모가 자식보다 작으면 
			if (parentNode < currentNode)
			{
				//스왑해준다.
				::swap(parentNode, currentNode);

				index = GetParentIndex(index);
			}
			else
			{
				break;
			}
		}
	}

private:
	int GetParentIndex(int index)
	{
		int rv = (index - 1) / 2;

		return rv;
	}

	int GetLeftChildIndex(int index)
	{
		int rv = (index * 2) + 1;
		return rv;
	}

	int GetRightChildIndex(int index)
	{
		int rv = (index * 2) + 2;
		return rv;
	}
};

