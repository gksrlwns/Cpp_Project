#include <iostream>

using namespace std;

struct Node
{
	int Data = 0;
	Node* Prev = nullptr;
	Node* Next = nullptr;
};


class LinkedList
{

public:
	void AddData(int data)
	{
		Node* newNode = new Node();
		newNode->Data = data;

		if (_root == nullptr)
		{
			_root = newNode;
		}
		else
		{
			//1. 마지막으로 이동한 후에
			/*Node* CurrentNode = Root;

			CurrentNode의 Next가 Nullptr 될때까지
			CurrentNode를 CurrentNode의 Next로 이동시킨다.*/

			Node* currentNode = _root;
			while (currentNode->Next != nullptr)
			{
				currentNode = currentNode->Next;
			}

			//2. 마지막노드의 Next포인터에 newNode를 연결한다.
			// 마지막노드 = CurrentNode
			currentNode->Next = newNode;
			newNode->Prev = currentNode;
		}
	}

	void RemoveData(int data)
	{
		/*	
		Node* CurrentNode = Root;

		CurrentNode의 Next가 내가 원하는 데이터가 나올때까지 
		CurrentNode를 CurrentNode의 Next로 이동시킨다.
		*/

		Node* currentNode = _root;
		while (currentNode->Next != nullptr)
		{
			currentNode = currentNode->Next;

			if (currentNode->Data == data)
			{
				break;
			}
		}

		if (currentNode->Data != data)
		{
			cout << "데이터를 찾지 못하였습니다." << endl;
			return;
		}

		//CurrentNode의 Prev의 Next가 CurrentNode의 Next로 변경한다.
		//CurrentNode의 Next의 Prev도 CurrentNode의 Prev로 변경한다.
		//그 이후에 CurrentNode를 삭제한다.

		currentNode->Prev->Next = currentNode->Next;
		if (currentNode->Next != nullptr)
		{
			currentNode->Next->Prev = currentNode->Prev;
		}

		delete currentNode;
		currentNode = nullptr;
	}

	int GetDataByIndex(int index)
	{
		Node* currentNode = _root;
		for (int i = 0; i < index; i++)
		{
			currentNode = currentNode->Next;
		}

		return currentNode->Data;
	}

public:
	Node* _root = nullptr;
};


void main()
{
	// Linked List

	LinkedList* linkedList = new LinkedList();

	for (int i = 0; i < 10; i++)
	{
		linkedList->AddData(i);
	}

	linkedList->RemoveData(5);
	linkedList->RemoveData(9);

	for (int i = 0; i < 8; i++)
	{
		cout << linkedList->GetDataByIndex(i) << endl;
	}

	cout << "완료" << endl;
	delete linkedList;
}