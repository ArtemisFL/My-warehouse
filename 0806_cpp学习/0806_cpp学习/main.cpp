#include<iostream>
#include<time.h>
using namespace std;

namespace N
{
	int a = 10;
	int b = 20;
	int Add(int left, int right)
	{
		return left + right;
	}
	int Sub(int left, int right)
	{
		return left - right;
	}
}
//ʹ�������ռ䷽��һ
/*int main()
{
	//printf("%d\n", a);//����
	printf("%d\n", N::a);
	printf("%d\n", N::Add(1, 8));
	system("pause");
	return 0;
}*/
//ʹ�������ռ䷽����
/*using N::b;
int main()
{
	printf("%d\n", N::a);
	//printf("%d\n", a);//����
	printf("%d\n", N::b);
	printf("%d\n", b);
	system("pause");
	return 0;
}*/
//ʹ�������ռ䷽����
/*using namespace N;
int main()
{
	printf("%d\n", N::a);
	printf("%d\n", b);
	printf("%d\n", Add(10, 20));
	system("pause");
	return 0;
}*/

//cpp���������
/*int main()
{
	cout << "hello world!!!" << endl;
	int a;
	double b;
	char c;

	cin >> a;
	cin >> b >> c;
	cout << a << endl;
	cout << b << "\n" << c << endl;

	system("pause");
	return 0;
}*/
//ȱʡ����
/*void TestFunc(int a = 99)
{
	cout << a << endl;
}

//ȫȱʡ����
void TestFunc1(int a = 10, int b = 20, int c = 30)
{
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	cout << "c=" << c << endl;
}
//��ȱʡ����
//void TestFunc2(int a, int b, int c);ȱʡ�����ڶ���ʱ���ܸ�������ֵ
void TestFunc2(int a, int b, int c = 20)
{
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	cout << "c=" << c << endl;
}

//��������
int Add(int left, int right)
{
	return left + right;
}
/*long Add(int left, int right)�β���ͬ������ֵ��ͬ����������
{
	return left + right;
}*/
/*double Add(double left, double right)
{
	return left + right;
}

long Add(long left, long right)
{
	return left + right;
}*/

//��������������������
/*void TestFunc(int a = 10)
{
	cout << "void TestFunc(int)" << endl;
}
void TestFunc(int a)
{
	cout << "void TestFunc(int)" << endl;
}*/

//����         ��������������������¿��ٿռ䣬���ͱ�����ͬ
/*void TestRef()
{
	int a = 10;
	int& ra = a;//ԭ����ʵ���Ƕ�����һ����ַ��a��ͬ��,����Ϊint�ı���ra

	printf("%p\n", &a);
	printf("%p\n", &ra);
}
//������
void TestConstRef()
{
	const int a = 10;
	//int& ra = a;//����a�ǳ���
	const int&ra = a;
	//int& b=10;   ����10�ǳ���
	const int& b = 10;
	double d = 12.34;
	//int& rd = d;���Ͳ�ƥ��
	//const int& rd = d;
}
//����������,������ʵ��������������
void Swap(int& left, int& right)
{
	int temp = left;
	left = right;
	right = temp;
}
//������ֵ
int& TestRefReturn(int& a)
{
	a += 10;
	return a;
}*/
//�������ͷ���ʱ������ֵ���������ڲ��ܺ���������
/*int& Add(int a, int b)
{
	int c = a + b;
	return c;
}*/
//��ֵ�����õ�Ч�ʱȽ�
/*struct A
{
	int a[10000];
};
void TestFun1(A a)
{}
void TestFun2(A& a)
{}
void TestRefAndValue()
{
	A a;
	size_t begin1 = clock();
	for (size_t i = 0; i < 10000; ++i)
		TestFun1(a);
	size_t end1 = clock();

	size_t begin2 = clock();
	for (size_t i = 0; i < 10000; ++i)
		TestFun2(a);
	size_t end2 = clock();

	cout << "TestFun1(int*)-time:" << end1 - begin1 << endl;
	cout << "TestFun2(int&)-time:" << end2 - begin2 << endl;
}*/
//ֵ�����õ���Ϊ����ֵ���͵����ܱȽ�
/*struct A
{
	int a[10000];
};
A a;
A TestFun1()
{
	return a;
}
A& TestFun2()
{
	return a;
}
void TestReturnByRefOrValue()
{
	//��ֵΪ�����ķ���ֵ����
	size_t begin1 = clock();
	for (size_t i = 0; i < 100000; i++)
		TestFun1();
	size_t end1 = clock();

	//��������Ϊ��������ֵ
	size_t begin2 = clock();
	for (size_t i = 0; i < 100000; i++)
		TestFun2();
	size_t end2 = clock();
	cout << "TestFun1 time:" << end1 - begin1 << endl;
	cout << "TestFun2 time:" << end2 - begin2 << endl;
}*/
//��������
/*inline void f(int i)
{
	cout << i << endl;
}*/
//auto�ؼ���
/*int TestAuto()
{
	return 10;
}
//auto �����Ƶ��ĳ���
void TestAuto(auto a)
{}
void TestAuto()
{
	int a[] = { 1, 2, 3 };
	auto b[] = { 4, 5, 6 };�����Ƶ�����
}*/
//ָ���ֵ
void f(int)
{
	cout << "f(int)" << endl;
}
void f(int*)
{
	cout << "f(int*)" << endl;
}
int main()
{
	f(0);
	f(NULL);//����NULL��ʵ����0����Ϊָ���ֵ�������ʣ��޷���ȷ���ú���
	f((int*)NULL);
	f(nullptr);//ָ���ֵ
	/*//���ڷ�Χ��ѭ��,foreach ѭ��
	int array[] = { 1, 2, 3, 4, 5 };
	for (auto& e : array)
		e *= 2;
	for (auto e : array)
		cout << e << endl;
	/*auto a = 1, b = 2;
	//auto c = 3, d = 4.0;���󣬱�����ֻ�ܶԵ�һ�����ͽ����Ƶ����Ƶ����������Ͷ�����������
	/*int x = 10;
	auto b = &x;
	auto *c = &x;
	auto &d = x;

	/*int a = 10;
	auto b = a;
	auto c = 'a';
	auto d = TestAuto();
	//auto e;    ���󣬱�����г�ʼ��*/
	/*cout << typeid(b).name() << endl;
	cout << typeid(c).name() << endl;
	cout << typeid(d).name() << endl;
	*b = 20;
	*c = 30;
	d = 40;
	
	/*f(10);
	/*int a = 10;
	int& ra = a;
	cout << "&a=" << &a << endl;
	cout << "&ra=" << &ra << endl;
	/*for (int i = 0; i < 10; i++)
		TestReturnByRefOrValue();
	/*for (int i = 0; i < 10; i++)
		TestRefAndValue();
	/*int& ret = Add(1, 2);
	Add(3, 4);
	cout << "Add(1,2)is:" << ret << endl;
	/*int a = 2;
	TestRefReturn(a);
	cout << a << endl;
	cout << TestRefReturn(a) << endl;
	/*int a = 10;
	int b = 20;
	Swap(a, b);
	printf("%d %d\n", a, b);
	TestRef();
	//TestFunc();
	/*TestFunc2(15, 21);
	TestFunc(10);*/
	/*cout << Add(10, 20) << endl;
	cout << Add(10.0, 20.0) << endl;
	cout << Add(10L, 20L) << endl;*/
	system("pause");
	return 0;
}