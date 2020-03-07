#pragma once
#include"Common.hpp"
#include<vector>

template<class T>
struct HashNode {
	HashNode(const T& data = T())
		:_pNext(nullptr)
		,_data(data)
	{}

	HashNode<T>* _pNext;
	T _data;
};

template<class T, class DF = DFDef<T>>
class HashBucket;

//������
template<class T, class DF = DFDef<T>>
struct HBIterator {
	typedef HashNode<T> Node;
	typedef HBIterator<T, DF> Self;
	HBIterator(Node* pNode = nullptr, HashBucket<T, DF>* ht = nullptr)
		:_pNode(pNode)
		, _ht(ht)
	{}
	T& operator*() {
		return _pNode;
	}
	T* operator->() {
		return &(_pNode->_data);
	}
	//�ܹ��ƶ�
	Self& operator++() {
		Next();
		return *this;
	}
	//����++
	Self operator++(int) {
		Self temp = (*this);
		Next();
		return temp;
	}
	//�Ƚ�
	bool operator!=(Self& s) {
		return _pNode != s._pNode;
	}
	bool operator==(Self& s) {
		return _pNode == s._pNode;
	}

	void Next() {
		if (_pNode->_pNext) {

			_pNode = _pNode->_pNext;
		}
		else {
			//pNode�ǵ�ǰ�����е����һ���ڵ�
			//��node����ĵ�һ���ǿ�Ͱ
			//���⣺���pNode������һ��Ͱ�еģ�֪����ϣ����������֪��pNode��Ͱ��
			size_t bucketNo = _ht->HashFunc(_pNode->_data) + 1;
			for (; bucketNo < _ht->_table.capacity(); ++bucketNo) {
				if (_ht->_table[bucketNo]) {
					//�ǿ�Ͱ�õ�
					_pNode = _ht->_table[bucketNo];
					return;
				}
			}
			_pNode = nullptr;
		}
	}
	HashNode<T>* _pNode;
	HashBucket<T, DF>* _ht;
};


//��������κ�����
//1.Ϊ���ඨ�������
//2.���������¸�����������
//3.����begin/end

template<class T, class DF>
class HashBucket {
	friend struct HBIterator<T, DF>;
	typedef HashNode<T> Node;
	typedef HBIterator<T, DF>iterator;
public:
	HashBucket(size_t capacity = 10)
		:_size(0)
	{
		_table.resize(GetNextPrime(10));
	}
	//����ʱ����ϣͰ�е�Ԫ����Ψһ��
	bool insertunique(const T& data) {
		//ͨ����ϣԪ�أ�����Ͱ��
		size_t bucketNo = HashFunc(data);

		//���ֵΪdata��Ԫ���ڹ�ϣͰ���Ƿ����
		Node* pCur = _table[bucketNo];
		while (pCur) {
			if (pCur->_data == data)
				return false;

			pCur = pCur->_pNext;
		}
		//�����½ڵ�,����ͷ��ķ�ʽ
		pCur = new Node(data);
		pCur->_pNext = _table[bucketNo];
		_table[bucketNo] = pCur;
		++_size;
		return true;
	}
	bool insertEqual(const T& data);

	bool eraseunique(const T& data) {
		//ͨ����ϣ��������data���ڵ�Ͱ��
		size_t bucketNo = HashFunc(data);

		//��bucketNo����Ӧ����������ֵΪdata�Ľڵ�
		Node* pCur = _table[bucketNo];
		Node* pPre = nullptr;
		while (pCur) {
			if (pCur->_data == data) {
				//ɾ��pCur�ڵ�ɾ��
				if (nullptr == pPre) {
					//ɾ����һ���ڵ�
					_table[bucketNo] = pCur->_pNext;
				}
				else {
					//ɾ���ǵ�һ���ڵ�
					pPre->_pNext = pCur->_pNext;
				}
				delete pCur;
				--_size;
				return true;
			}
			else {
				pPre = pCur;
				pCur = pCur->_pNext;
			}
		}
		return false;
	}

	bool eraseEqual(const T& data);

	Node* find(const T& data)const {
		//����data���ڵ�Ͱ��
		size_t bucketNo = HashFunc(data);

		//��bucketNo����Ӧ����������ֵΪdata�Ľڵ�
		Node* pCur = _table[bucketNo];
		while (pCur) {
			if (pCur->_data == data)
				return pCur;
			pCur = pCur->_pNext;
		}
		return nullptr;
	}
	size_t size()const {
		return _size;
	}
	bool empty()const {
		return 0 == _size;
	}

	iterator begin() {
		//�ҵ�һ���ǿ�Ͱ
		for (size_t bucket = 0; bucket < _table.capacity(); ++bucket) {
			if (_table[bucket])
				return iterator(_table[bucket], this);
		}
		return end();
	}
	iterator end() {
		return iterator(nullptr, this);
	}
	void PrintHashBucket() {
		for (size_t bucketNo = 0; bucketNo < _table.capacity(); ++bucketNo) {
			Node* pCur = _table[bucketNo];
			std::cout << "_table[" << bucketNo << "]:";
			while (pCur) {
				std::cout << pCur->_data << "--->";
				pCur = pCur->_pNext;
			}
			std::cout << "NULL" << std::endl;
		}
	}
private:
	//����
	void CheckCapacity() {
		if (_size == _table.capacity()) {

		}
	}
	size_t HashFunc(const T& data) const {
		return DF()(data) % _table.capacity();
	}
private:
	std::vector<Node*> _table;
	size_t _size;
};

#include<iostream>
using namespace std;

void TestHashBucket() {
	HashBucket<int> ht;
	int array[] = { 1,4,7,9,6,5 };
	for (auto e : array)
		ht.insertunique(e);

	cout << ht.size() << endl;
	ht.PrintHashBucket();

	ht.insertunique(44);
	ht.insertunique(54);

	auto it = ht.begin();
	while (it != ht.end()) {
		cout << *it << endl;
		++it;
	}
	cout << endl;
	ht.PrintHashBucket();

	ht.eraseunique(44);
	if (ht.find(44)) {
		cout << "44 is in hashbucket" << endl;
	}
	else {
		cout << "44 is not in hashbucket" << endl;
	}
	cout << ht.size() << endl;
	ht.PrintHashBucket();
}