#pragma once
#include <iostream>

using namespace std;


template <typename T>
struct Node
{
	T Data = 0;
	Node<T>* Prev = nullptr;
	Node<T>* Next = nullptr;
};



template <typename T>
class LinkedList
{

public:
	void AddData(T data);
	void RemoveData(T data);
	T GetDataByIndex(int index);
	T operator[](int index);

public:
	Node<T>* _root = nullptr;
};


template <typename T>
void LinkedList<T>::AddData(T data)
{
	Node<T>* newNode = new Node<T>();
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

		Node<T>* currentNode = _root;
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

template <typename T>
void LinkedList<T>::RemoveData(T data)
{
	/*
	Node* CurrentNode = Root;

	CurrentNode의 Next가 내가 원하는 데이터가 나올때까지
	CurrentNode를 CurrentNode의 Next로 이동시킨다.
	*/

	Node<T>* currentNode = _root;
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

template <typename T>
T LinkedList<T>::GetDataByIndex(int index)
{
	Node<T>* currentNode = _root;
	for (int i = 0; i < index; i++)
	{
		currentNode = currentNode->Next;
	}

	return currentNode->Data;
}

template <typename T>
T LinkedList<T>::operator[](int index)
{
	return this->GetDataByIndex(index);
}