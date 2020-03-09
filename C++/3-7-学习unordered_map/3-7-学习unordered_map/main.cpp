#include<iostream>
#include"UnorderedMap.hpp"
#include"UnorderedSet.hpp"
#include"HashBucket.hpp"
using namespace std;
void TestUnorderedMAP()
{
	bite::unordered_map<string, string> m;

	// �����ֵ�Ե����ַ�ʽ��pair�ṹ��  make_pair
	m.insert(pair<string, string>("�ν�", "��ʱ��"));
	m.insert(pair<string, string>("����", "��ţ"));
	m.insert(pair<string, string>("�ֳ�", "����ͷ"));

	m.insert(make_pair("����", "����"));

	cout << m.size() << endl;
	cout << m.bucket_count() << endl;  // Ͱ�ĸ���
	cout << m.bucket_size(0) << endl;  // 0��Ͱ�е�Ԫ�ظ���
	cout << m.bucket("�ν�") << endl;   // ��ȡkey���ڵ�Ͱ��

	// key�����ظ�
	m.insert(make_pair("����", "������"));
	cout << m.size() << endl;


	// []�����key���ڣ�ֱ�ӷ�����key����Ӧ��value
	cout << m["����"] << endl;   // ��һ��key���������key��Ӧ��value
	cout << m.size() << endl;

	// []: ���key�����ڣ�<key, Ĭ��value>����һ����ֵ�ԣ�Ȼ������뵽�����У�����Ĭ�ϵ�value
	cout << m["³��"] << endl;
	cout << m.size() << endl;

	m.erase("³��");
	cout << m.size() << endl;

	m.clear();
}
int main() {

	TestUnorderedMAP();
	system("pause");
	return 0;
}