#pragma once
#include<vector>
#include"Common.hpp"

enum State { EMPTY, EXIST, DELETE };

template<class T>
struct Elem {
	Elem(const T& val = T())
		:val_(val)
		, state_(EMPTY)
	{}
	T val_;
	State state_;
};

template<class T, class DF = DFInt, bool isLine = true>
class HashTable {
public:
	HashTable(size_t capacity = 5)
		:size_(0)
		,total_(0)
	{
		//vec_.resize(GetNextPrime(capacity));
		vec_.resize(capacity);
	}
	bool Insert(const T& num) {
		CheckCapacity();//����Ƿ���Ҫ����

		size_t addr = HashAddr(num);
		size_t i = 0;
		while (vec_[addr].state_ != EMPTY) {
			if (vec_[addr].state_ == EXIST && vec_[addr].val_ == num)
				return false;
			
			if (isLine) {   //�߳�̽��
				++addr;
				if (addr == vec_.size())
					addr = 0;
			}
			else {      //����̽��
				++i;
				addr = addr + 2 * i + 1;
				addr %= vec_.size();
			}
		}
		vec_[addr].val_ = num;
		vec_[addr].state_ = EXIST;
		++size_;
		++total_;
		return true;
	}
	int Find(const T& num) {
		size_t addr = HashAddr(num);
		size_t i = 0;
		while (vec_[addr].state_ != EMPTY) {
			if (vec_[addr].state_ == EXIST && vec_[addr].val_ == num)
				return addr;

			if (isLine) {   //�߳�̽��
				++addr;
				if (addr == vec_.size())
					addr = 0;
			}
			else {      //�ٴι�ϣ
				++i;
				addr = addr + 2 * i + 1;
				addr %= vec_.size();
			}
		}
		return -1;
	}
	bool Erase(const T& num) {
		int addr = Find(num);
		if (addr != -1) {
			vec_[addr].state_ = DELETE;
			--size_;
			return true;
		}
		return false;
	}
	size_t Size() const{
		return size_;
	}
private:
	void CheckCapacity() {
		if (1.0*(total_ + 1) / vec_.size() >= 0.7) {
			size_t newCapacity = GetNextPrime(vec_.size());
			HashTable<T,DF,isLine> newTH(newCapacity);
			for (const auto& e:vec_) {
				if (e.state_ == EXIST)
					newTH.Insert(e.val_);
			}
			Swap(newTH);
		}
	}
	void Swap(HashTable<T,DF,isLine>& ht) {
		vec_.swap(ht.vec_);
		total_ = size_;     //û�д���ɾ��״̬�������� ����total ,size����  ����Ҫ����
	}
	size_t HashAddr(const T& num) {
		return DF()(num) % vec_.size();
	}
private:
	size_t size_;
	size_t total_;
	std::vector<Elem<T>> vec_;
};