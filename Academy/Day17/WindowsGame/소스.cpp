#include <iostream>

using namespace std;

class Singleton
{
public:
	static Singleton* GetInstence()
	{
		static Singleton instance;
		return &instance;
	}
private:
	Singleton(){}
	~Singleton() {}
};


int main()
{
	cout << Singleton::GetInstence() << endl;
}