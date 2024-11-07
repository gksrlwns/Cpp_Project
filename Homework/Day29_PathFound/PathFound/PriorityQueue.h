#pragma once
#include <vector>
#include <assert.h>
using namespace std;

template <typename T>
class PriorityQueue
{
private:
	vector<T> _arr;

public:
	T& Peek()
	{
		assert(0 < _arr.size());
		return arr[0];
	}

	bool Empty()
	{
		return _arr.size() == 0;
	}

	void Pop()
	{

	}

	void Push(T data)
	{

	}
};

