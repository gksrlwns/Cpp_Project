#pragma once
#include <iostream>

using namespace std;

template <typename T>
struct Node
{
	Node<T>* Parent;
	Node<T>* Left;
	Node<T>* Right;
	T Data;
};

template <typename T>
class BinaryTree
{
public:
	void AddData(T data);
	void RemoveData(T data);
	Node<T>* GetNode(T data);

private:
	//자식이 둘다있는 경우에는 사용못함 참고
	void RemoveNode(Node<T>* node);
private:
	Node<T>* _root = nullptr;
};


template <typename T>
void BinaryTree<T>::AddData(T data)
{
	// 데이터가 없을때까지 왼쪽 / 오른쪽으로 이동한다.
	// 데이터가 없는부분에서 newNode를 연결

	Node<T>* newNode = new Node<T>();
	newNode->Data = data;
	newNode->Left = nullptr;
	newNode->Right = nullptr;
	newNode->Parent = nullptr;

	//데이터가 없으면
	// _root 에 newNode 세팅하고 종료
	if (_root == nullptr)
	{
		_root = newNode;
		return;
	}

	if (this->GetNode(data) != nullptr)
	{
		cout << "중복된 데이터는 추가할수 없습니다." << endl;
		return;
	}

	Node<T>* current = _root;
	while (true)
	{
		if (current->Data < data)
		{
			if (current->Right == nullptr)
			{
				newNode->Parent = current;
				current->Right = newNode;
				break;
			}
			else
			{
				current = current->Right;
			}
			
		}
		else if (data < current->Data)
		{
			if (current->Left == nullptr)
			{
				newNode->Parent = current;
				current->Left = newNode;
				break;
			}
			else
			{
				current = current->Left;
			}
		}
	}

}

template <typename T>
void BinaryTree<T>::RemoveData(T data)
{
	//1. 둘다없을때 삭제하는 방법
	//	- 1) 삭제하려는 노드를 찾는다.
	//	- 2) 부모와의 연을 끊은다음에
	//	- 3) 삭제하려는 노드를 삭제한다.

	Node<T>* findNode = this->GetNode(data);

	//없는걸 삭제하려고할수있으니
	if (findNode == nullptr)
	{
		cout << "없는 데이터입니다." << endl;
		return;
	}

	//1. 자식이 둘다있을때
	if (findNode->Left != nullptr && findNode->Right != nullptr)
	{
		Node<T>* swapNode = findNode->Right;
		
		// 1. 대체할 노드찾기.
		while (swapNode->Left != nullptr)
		{
			swapNode = swapNode->Left;
		}

		// 2. 삭제할 노드를 대체할 노드로 값변경
		findNode->Data = swapNode->Data;

		// 3. 대체할노드를 삭제한다. (삭제방법은 위 1,2와 동일)
		RemoveNode(swapNode);
	}
	else
	{
		RemoveNode(findNode);
	}

}

template <typename T>
void BinaryTree<T>::RemoveNode(Node<T>* node)
{
	if (node == nullptr) return;

	//1. 자식이 둘다없을때
	if (node->Left == nullptr && node->Right == nullptr)
	{
		//부모와의 연끊기.
		//내가 왼쪽이라면 왼쪽 연끊기
		if (node->Parent->Left == node)
		{
			node->Parent->Left = nullptr;
		}
		//내가 오른쪽이라면 오른쪽 연끊기
		if (node->Parent->Right == node)
		{
			node->Parent->Right = nullptr;
		}

		delete node;
		node = nullptr;
	}
	//2. 자식이 한쪽만 있을때 (오른쪽만 있을때)
	else if (node->Left == nullptr && node->Right != nullptr)
	{
		//부모와의 연을 내 자식으로 대체해주기
		//내가 왼쪽이라면 부모의 왼쪽을 내 자식으로 연결
		if (node->Parent->Left == node)
		{
			node->Parent->Left = node->Right;
		}
		//내가 오른쪽이라면 부모의 오른쪽을 내 자식으로 연결
		if (node->Parent->Right == node)
		{
			node->Parent->Right = node->Right;
		}

		delete node;
		node = nullptr;
	}
	//2. 자식이 한쪽만 있을때 (왼쪽만 있을때)
	else if (node->Left != nullptr && node->Right == nullptr)
	{
		//부모와의 연을 내 자식으로 대체해주기
		//내가 왼쪽이라면 부모의 왼쪽을 내 자식으로 연결
		if (node->Parent->Left == node)
		{
			node->Parent->Left = node->Left;
		}
		//내가 오른쪽이라면 부모의 오른쪽을 내 자식으로 연결
		if (node->Parent->Right == node)
		{
			node->Parent->Right = node->Left;
		}

		delete node;
		node = nullptr;
	}
}

template <typename T>
Node<T>* BinaryTree<T>::GetNode(T data)
{
	Node<T>* current = _root;
	while (current != nullptr && current->Data != data)
	{
		if (current->Data < data)
		{
			current = current->Right;
		}
		else if (data < current->Data)
		{
			current = current->Left;
		}
	}

	return current;
}