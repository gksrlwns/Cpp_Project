#include "pch.h"
#include "PriorityQueue.h"

struct PQNode
{
	int x;
	int y;
	int cost;

	bool operator<(const PQNode& other) const
	{
		return cost < other.cost;
	}

	bool operator>(const PQNode& other) const
	{
		return cost > other.cost;
	}
};

void main()
{
	/*PriorityQueue<PQNode> p;
	{
		PQNode node = { 1, 1, 3 };
		p.Push(node);
	}
	{
		PQNode node = { 2, 1, 5 };
		p.Push(node);
	}
	{
		PQNode node = { 1, 2, 10 };
		p.Push(node);
	}
	{
		PQNode node = { 2, 2, 50 };
		p.Push(node);
	}
	while (false == p.Empty())
	{
		cout << "Top : " << p.Peek().cost << endl;
		p.Pop();
	}*/



	//priority_queue<int, vector<int>, greater<int>> q;
	//priority_queue<int> q;
	/*q.push(10);
	q.push(30);
	q.push(50);
	while (false == q.empty())
	{
		cout << "Top : " << q.top() << endl;
		q.pop();
	}*/
}