#include<iostream>
#include<thread>
#include <mutex>
#include <memory>
using namespace std;

/*class Date
{
public:
	Date() { cout << "Date()" << endl; }
	~Date(){ cout << "~Date()" << endl; }

	int _year;
	int _month;
	int _day;
};

template <class T>
class SharedPtr
{
public:
	SharedPtr(T* ptr = nullptr)
		: _ptr(ptr)
		, _pRefCount(new int(1))
		, _pMutex(new mutex)
	{}

	~SharedPtr() { Release(); }

	SharedPtr(const SharedPtr<T>& sp)
		: _ptr(sp._ptr)
		, _pRefCount(sp._pRefCount)
		, _pMutex(sp._pMutex)
	{
		AddRefCount();
	}

	// sp1 = sp2    
	SharedPtr<T>& operator=(const SharedPtr<T>& sp)
	{
		//if (this != &sp)        
		if (_ptr != sp._ptr)
		{
			// �ͷŹ���ľ���Դ            
			Release();

			// ��������¶������Դ�����������ü���            
			_ptr = sp._ptr;
			_pRefCount = sp._pRefCount;
			_pMutex = sp._pMutex;

			AddRefCount();
		}

		return *this;
	}

	T& operator*() { return *_ptr; }
	T* operator->() { return _ptr; }

	int UseCount() { return *_pRefCount; }
	T* Get() { return _ptr; }

	void AddRefCount()
	{
		// ��������ʹ�ü�1��ԭ�Ӳ���        
		_pMutex->lock();
		++(*_pRefCount);
		_pMutex->unlock();
	}
private:
	void Release()
	{
		bool deleteflag = false;
		// ���ü�����1���������0�����ͷ���Դ        
		(*_pMutex).lock();
		if (--(*_pRefCount) == 0)
		{
			delete _ptr;
			delete _pRefCount;
			deleteflag = true;
		}
		(*_pMutex).unlock();
		if (deleteflag == true)
			delete _pMutex;
	}
private:
	int* _pRefCount; // ���ü���    
	T*   _ptr;       // ָ�������Դ��ָ��       
	mutex* _pMutex;      // ������
};

void SharePtrFunc(SharedPtr<Date>& sp, size_t n)
{
	cout << sp.Get() << endl;
	for (size_t i = 0; i < n; ++i)
	{
		// ��������ָ�뿽����++����������ָ��������--�������������̰߳�ȫ�ġ�        
		SharedPtr<Date> copy(sp);

		// ��������ָ����ʹ������Դ�������̰߳�ȫ�ġ��������ǿ�����Щֵ�����߳�++��2n�Σ������� �տ����Ľ������һ���Ǽ���2n        
		copy->_year++;
		copy->_month++;
		copy->_day++;
	}
}

int main()
{
	SharedPtr<Date> p(new Date);
	cout << p.Get() << endl;

	const size_t n = 100;
	thread t1(SharePtrFunc, p, n);
	thread t2(SharePtrFunc, p, n);

	t1.join();
	t2.join();

	cout << p->_year << endl;
	cout << p->_month << endl;
	cout << p->_day << endl;

	system("pause");
	return 0;
}*/
/*#include <thread> 
#include <mutex>

// C++11�Ŀ���Ҳ��һ��lock_guard�������LockGuard��������ʵ����Ϊ��ѧϰ����ԭ�� 
template<class Mutex>
class LockGuard
{
public:
	LockGuard(Mutex& mtx)
		:_mutex(mtx)
	{
		_mutex.lock();
	}

	~LockGuard()
	{
		_mutex.unlock();
	}

	LockGuard(const LockGuard<Mutex>&) = delete;

private:
	// ע���������ʹ�����ã��������ľͲ���һ������������    
	Mutex& _mutex;
};

mutex mtx;
static int n = 0;

void Func()
{
	for (size_t i = 0; i < 1000000; ++i)
	{
		LockGuard<mutex> lock(mtx);
		++n;
	}
}
typedef int(*FUNC)();
int DoSomething(int i)
{
	cout << "DoSomething" << endl;
	return 0;
}

void Test()
{
	//     
	// reinterpret_cast���Ա�������FUNC�Ķ��巽ʽȥ����DoSomething����     
	// ���Էǳ���BUG������ת������ָ��Ĵ����ǲ�����ֲ�ģ����Բ�����������     
	// C++����֤���еĺ���ָ�붼��һ����ʹ�ã�������������ʱ�������ȷ���Ľ��     
	//     
	FUNC f = DoSomething;
	f();
}
int main()
{
	Test();
	/*int begin = clock();
	thread  t1(Func);
	thread  t2(Func);

	t1.join();
	t2.join();

	int end = clock();

	cout << n << endl;
	cout << "cost time:" << end - begin << endl;
	system("pause");
	return 0;
}
class A 
{ 
public:     
	virtual void f(){} 
};

class B : public A {};

void fun(A* pa) {   
	// dynamic_cast���ȼ���Ƿ���ת���ɹ����ܳɹ���ת���������򷵻�   
	B* pb1 = static_cast<B*>(new A());
	B* pb2 = dynamic_cast<B*>(pa);      
	cout<<"pb1:" <<pb1<< endl;   
	cout<<"pb2:" <<pb2<< endl; 
}
int main() 
{ 
	A a;     
	B b;     
	fun(&a);     
	fun(&b);     
	system("pause");
	return 0; 
}*/
class A
{
public:
	virtual void test()
	{
		cout << "A-test" << endl;
	}
	void test2()
	{
		cout << "A-test2" << endl;
	}
	void test3()
	{
		cout << "A-test3" << endl;
	}
	/*A(int a)
	{
		cout << "A(int a)" << endl;
	}
	A(const A& a)
	{
		cout << "A(const A& a)" << endl;
	}
private:
	int _a*/
};
class B:public A
{
public:
	virtual void test()
	{
		cout << "B-test" << endl;
	}
	void test1()
	{
		cout << "B-test1" << endl;
	}
	void test2()
	{
		cout << "B-test2" << endl;
	}
};
int main()
{
	B *pa = static_cast<B*>(new A());
	pa->test1();
	pa->test2();
	pa->test3();
	//A a1(1);

	// ��ʽת��-> A tmp(1); A a2(tmp);     
	//A a2 = 1;
	system("pause");
	return 0;
}
