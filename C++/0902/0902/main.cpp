#include<iostream>
using namespace std;

class A
{
public:
	A()
	{
		cout << "~A" << endl;
	}
};
class B :public A
{
private:
	A _a;
public:
	B(A &a)
		:_a(a)
	{
		cout << "~B" << endl;
	}
};
void test()
{
	A a;
	B b(a);
}
/*class Man
{
public:
	Man()
	{
		cout << "����man�Ĺ��캯�����ұ�������" << endl;
	}
	~Man()
	{
		cout << "����man�������������ұ�����" << endl;
	}
};
class Boy
{
public:
	Boy()
	{
		cout << "����boy�Ĺ��캯�����ұ�������" << endl;
	}
	~Boy()
	{
		cout << "����boy�������������ұ�������" << endl;
	}
};

class Girl
{
public:
	Girl()
	{
		cout << "����girl�Ĺ��캯�����ұ�������" << endl;
	}
	~Girl()
	{
		cout << "����girl�������������ұ�������" << endl;
	}
};

class Teenager : public Man
{
	Boy boy;
	Girl girl;
public:
	Teenager()
	{
		cout << "����teenager�Ĺ��캯�����ұ�������" << endl;
	}
	~Teenager()
	{
		cout << "����teenager�������������ұ�������" << endl;
	}
};
void test()
{
	Teenager teenager;
}*/
int main()
{
	test();
	/*A a;
	B b(a);
	/*char a[80] = " 0123\0789 ";
	char b[80] = " 0123\0779 ";
	//cout << strlen(a) << endl;
	//cout << strlen(b) << endl;
	printf("%c\n", 7);*/

	system("pause");
	return 0;
}