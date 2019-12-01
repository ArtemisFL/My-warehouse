#include<iostream>
using namespace std;

typedef void(*FUNC)();
int DoSomething(int i)
{
	cout << "DoSomething" << endl;
	return 0;
}

void Test()
{
	//�˴��벻����ֲ������ȫ     
	FUNC f = reinterpret_cast<FUNC>(DoSomething);
	f();
}
void Test1()
{
	const int a = 2;
	int* p = const_cast<int*>(&a);
	*p = 3;
	cout << a << endl;
	cout << *p << endl;
}

/*class A
{
public:
	virtual void f() {}
};

class B : public A {};*/

/*void fun(A* pa) {
	// dynamic_cast���ȼ���Ƿ���ת���ɹ����ܳɹ���ת���������򷵻�
	B* pb1 = static_cast<B*>(new A());
	B* pb2 = dynamic_cast<B*>(pa);
	cout << "pb1:" << pb1 << endl;
	cout << "pb2:" << pb2 << endl;
}*/

class A
{
public:
	A(int a)
	{
		cout << "A(int a)" << endl;
	}

	A(const A& a)
	{
		cout << "A(const A& a)" << endl;
	}
private:
	int _a;
};

int main()
{
	A a1(1);

	// ��ʽת��-> A tmp(1); A a2(tmp);     
	A a2 = 1;

	/*A a;
	B b;
	fun(&a);
	fun(&b);
	return 0;*/
}

/*int main() {
	Test1();
	//Test();
	/*double d = 5;
	int  a = static_cast<int>(d);
	//int  b = reinterpret_cast<int>(d);
	cout << a << endl << endl;
	system("pause");
	return 0;
}*/

