#pragma once

#include "HashBucket.hpp"
#include <string>
#include <iostream>
using namespace std;

namespace bite
{
	template<class K, class V>
	class unordered_map
	{
	public:
		// δ��typename֮ǰ�����������ܻὫHashBucket<ValueType, KOFV>::iterator���������еĳ�Ա���������д���
		// ��Ϊ��Ա����Ҳ�Ǹ�������::��̬��Ա��������
		// typename: �ڴ˴������þ�����ȷ���߱��������˴���iterator�ǹ�ϣͰ�е�һ������
		typedef pair<K, V> ValueType;

		struct KOFV
		{
			const K& operator()(const ValueType& data)const
			{
				return data.first;
			}
		};

		typename typedef HashBucket<ValueType, KOFV>::iterator iterator;

	public:
		unordered_map()
			: _ht()
		{}

		iterator begin()
		{
			return _ht.begin();
		}

		iterator end()
		{
			return _ht.end();
		}

		bool empty()const
		{
			return _ht.empty();
		}

		size_t size()const
		{
			return _ht.size();
		}

		pair<iterator, bool> insert(const ValueType& data)
		{
			return _ht.insertunique(data);
		}

		size_t erase(const K& key)
		{
			return _ht.eraseunique(ValueType(key, V()));
		}

		iterator find(const K& key)
		{
			return _ht.find(ValueType(key, V()));
		}

		void clear()
		{
			_ht.clear();
		}

		void swap(const unordered_map<K, V>& m)
		{
			_ht.swap(m._ht);
		}

		V& operator[](const K& key)
		{
			return (*(insert(ValueType(key, V())).first)).second;
		}

		size_t bucket_count()const
		{
			return _ht.bucket_count();
		}

		size_t bucket_size(size_t n)const
		{
			return _ht.bucket_size(n);
		}

		size_t bucket(const K& key)
		{
			return _ht.bucket(ValueType(key, V()));
		}

	private:
		HashBucket<ValueType, KOFV> _ht;
	};
}

