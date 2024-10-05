#include <iostream>
#include "BinaryTree.h"
using namespace std;

struct Student
{
	int Math;
	int Korea;
public:
	bool operator<(Student student)
	{
		if (this->Math + this->Korea < student.Korea + student.Math)
		{
			return true;
		}

		return false;
	}

	bool operator!=(Student student)
	{
		if (this->Math == student.Math && this->Korea == student.Korea)
		{
			return false;
		}

		return true;
	}
};

void main()
{
	srand(time(NULL));

	BinaryTree<Student> bt;

	Student student1{ 100, 80 };
	Student student2{ 50, 100 };


	bt.AddData(student1);
	bt.AddData(student2);


	//for (int i = 0; i < 1000; i++)
	//{
	//	bt.AddData(rand());
	//}

	//bt.AddData(-2);
	//bt.AddData(-10);
	//bt.AddData(-1);

	//Node<int>* a = bt.GetNode(-2);
	//cout << "a : " << a << endl;

	//bt.RemoveData(-2);

	//a = bt.GetNode(-2);
	//cout << "a : " << a << endl;
}