/*#include<iostream>
using namespace std;

void test()
{
	int *p1 = (int*)malloc(sizeof(int));
	free(p1);

	int *p2 = (int*)calloc(4, sizeof(int));
	int *p3 = (int*)realloc(p2, sizeof(int) * 10);

	free(p3);
	free(p2);//�˴������ظ�free
}
void test()
{
	int *ptr4 = new int;
	int *ptr5 = new int(10);//��ʼ��Ϊ10
	int *ptr6= new int[3];

	delete ptr4;
	delete ptr5;
	delete[] ptr6;
}
class Test
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
void test()
{
	Test *pt = (Test*)malloc(sizeof(Test));
	new(pt)Test;
}
/*void Test1()
{
	Test* p1 = (Test*)malloc(sizeof(Test));
	free(p1);

	Test* p2 = (Test*)malloc(sizeof(Test) * 10);
	free(p2);
}
void Test2()
{
	Test* p1 = new Test;
	delete p1;

	Test* p2 = new Test[10];
	delete[] p2;
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

	HeapOnly(const HeapOnly&);

	HeapOnly(const HeapOnly&) = delete;
};


int main()
{
	HeapOnly *h1 = new HeapOnly;
	//test();
	//Test1();
	//Test2();

	system("pause");
	return 0;
}*/

#include <iostream> 
#include <mutex> 
#include <thread> 
using namespace std;

class Singleton 
{
public:    
	static Singleton* GetInstance() 
	{        
		// ע������һ��Ҫʹ��Double-Check�ķ�ʽ���������ܱ�֤Ч�ʺ��̰߳�ȫ        
		if (nullptr == m_pInstance) 
		{ 
			m_mtx.lock();            
			if (nullptr == m_pInstance) 
			{ 
				m_pInstance = new Singleton(); 
			}            
			m_mtx.unlock();
		}        
		return m_pInstance;
	}
	// ʵ��һ����Ƕ����������        
	class CGarbo 
	{    
	public:        
		~CGarbo()
		{            
			if (Singleton::m_pInstance)                
				delete Singleton::m_pInstance;
		}    
	};

	// ����һ����̬��Ա�������������ʱ��ϵͳ���Զ������������������Ӷ��ͷŵ�������    
	static CGarbo Garbo;

private:    
	// ���캯��˽��    
	Singleton(){};

	// ������    
	Singleton(Singleton const&);    
	Singleton& operator=(Singleton const&);

	static Singleton* m_pInstance; // ��������ָ��    
	static mutex m_mtx;            //������ 
};

Singleton* Singleton::m_pInstance = nullptr; 
Singleton::CGarbo Garbo; 
mutex Singleton::m_mtx;

void func(int n) 
{ 
	cout << Singleton::GetInstance() << endl; 
}

// ���̻߳�������ʾ����GetInstance()�����Ͳ����������� 
int main() 
{    
	void* p = new char[0xfffffffeul];    
	cout << "new:" << p << endl;
	system("pause");
	return 0;
	/*thread t1(func, 10);    
	thread t2(func, 10);

	t1.join();    
	t2.join();

	cout << Singleton::GetInstance() << endl;
	cout << Singleton::GetInstance() << endl*/
}