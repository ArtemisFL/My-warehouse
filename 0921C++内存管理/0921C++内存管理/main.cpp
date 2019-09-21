#include<iostream>
using namespace std;

/*class Test
{
public:
	Test()
		:_data(0)
	{
		cout << "Test():" << this << endl;
	}
	~Test()
	{
		cout << "~Test():" << this << endl;
	}
private:
	int _data;
};
/*void Test1()
{
	Test* p1 = (Test*)malloc(sizeof(Test));
	free(p1);
	Test* p2 = (Test*)malloc(sizeof(Test) * 10);
	free(p2);
	//malloc(15);
	_CrtDumpMemoryLeaks();
}
void Test2()
{
	Test* p1 = new Test;
	delete p1;
	Test* p2 = new Test[10];
	delete[] p2;
	//malloc(15);
	_CrtDumpMemoryLeaks();
}
class HeapOnly
{
public:
	static HeapOnly* CreateObject()
	{
		return new HeapOnly;
	}
private:
	HeapOnly(){}
	HeapOnly(const HeapOnly&) = delete;
};
class StackOnly
{
public:
	static StackOnly CreateObject()
	{
		return StackOnly();
	}
	void test()
	{
		cout << data << endl;
	}
private:
	StackOnly()
		:data(11)
	{
		cout << "123" << endl;
	}
	int data = 12;
};

/*void del(int L[], int len, int x, int y)
{
	for (int i = 0; i < len; i++)
	{
		if (L[i]>x&&L[i] < y)
		{
			int index = i + 1;
			while (index != len)
			{
				L[index - 1] = L[index];
				index++;
			}
			len--;
			i--;
		}
	}
}*/
/*class StackOnly
{
public:
	StackOnly()
	//	:data(11)
	{
		cout << "123" << endl;
	}
private:
	void* operator new (size_t size);
	void operator delete(void* p);
	//int data = 12;
};
class test
{
public:
	test()
	{
		cout << "123" << endl;
	}
private:
	void* operator new (size_t size);
	void operator delete(void* p);
	int data = 12;
};*/

class Test
{
public:
	Test()
	{
		_data = 10;
		//_p = new int;
		cout << "Test():" << this << endl;
	}

	~Test()
	{
		//delete _p;
		cout << "~Test():" << this << endl;
	}

private:
	int _data;
	//int* _p;
};

// �����Զ������ͣ�ֻҪ�漰��[]����Ȼ�����
// new����ù��캯��
// free���������������--�����е���Դ���ᱻ����
void Test2()
{
	Test* p3 = new Test;
	Test* p4 = new Test;
	free(p3);     //freeֻ���ͷ��˶������ڵ��ڴ�ռ䣬����Զ��������еĳ�Ա����
	              //��������Դ�����޷��ͷŸ���Դ��������ڴ�й¶����Ϊû�е�������������
	delete[] p4;  //delete[] ���Զ���������ֻҪû�к�new[]ƥ��ʹ�þͻ�����ʱ����

	// malloc����ռ�ʱ������ù��캯��--�������������С��ͬ��һ���ڴ�ռ�
	// ���ܽ��ÿ��ڴ�ռ俴����һ������

	Test* p1 = (Test*)malloc(sizeof(Test));
	Test* p2 = (Test*)malloc(sizeof(Test));
	delete p1;    // ���������������������е���Դ������Զ��������еĳ�Ա����
	              //��������Դ�����ᱨ����Ϊmallocû�е��ù��캯����û�и���
				  //����Դ�ı��������ڴ棬��ʱ�ͷſռ䵱Ȼ�����
	delete[] p2;  //delete[] ���Զ���������ֻҪû�к�new[]ƥ��ʹ�þͻ�����ʱ����

	Test* p5 = new Test[10];
	Test* p6 = new Test[10];
	free(p5);      //free�ͷ�new[]����������ʱ�����
	delete p6;     //delete�ͷ�new[]����������ʱ�����
	_CrtDumpMemoryLeaks();
}
int main()
{
	Test2();
	/*StackOnly* s1 = &(StackOnly::CreateObject());
	s1->test();
	//test s1;
	//new test;
	//StackOnly s1;
	//new StackOnly;
	//cout << s1.data << endl;
	//s1.test();
	/*int a[] = { 0, 2, 6, 9, 8, 5, 3, 1, 4, 7 };
	del(a, 10, 3, 7);
	/*HeapOnly* p1 = HeapOnly::CreateObject();
	HeapOnly* p3 = HeapOnly::CreateObject();
	StackOnly p2;
	//StackOnly* p2 = &(StackOnly::CreateObject());
	cout << p1 << '\n' << p3 << '\n' << &p2 << endl;

	/*Test t1;
	Test *t2 = new Test;
	cout << &t1 << '\n' << t2 << endl;
	/*void* p = new char[0xfffffffful];    
	cout << "new:" << p << endl;

	/*Test* p1 = (Test*)malloc(sizeof(Test));
	new(p1)Test;
	/*Test2();
	/*Test2();
	_CrtDumpMemoryLeaks();
	/*int *p1 = (int*)malloc(sizeof(int));
	free(p1);
	int *p2 = (int*)calloc(4, sizeof(int));
	int *p3 = (int*)realloc(p2, sizeof(int) * 10);
	//free(p2);
	free(p3);
	free(p2);*/

	system("pause");
	return 0;
}