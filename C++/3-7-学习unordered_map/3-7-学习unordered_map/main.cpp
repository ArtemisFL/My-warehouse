#include"HashBucket.hpp"
#include<iostream>
using namespace std;

/*void test_unordered_map() {
	unordered_map<string, string> m;
	//�����ֵ�Ե����ַ�ʽ
	m.insert(pair<string, string>("�ν�", "��ʱ��"));
	m.insert(pair<string, string>("����", "��ţ"));
	m.insert(pair<string, string>("�ֳ�", "����ͷ"));
	
	m.insert(make_pair("����", "����"));

	cout << m.size() << endl;
	cout << m.bucket_count() << endl;   //Ͱ�ĸ���
	cout << m.bucket_size(0) << endl;   //0��Ͱ�еĸ���
	cout << m.bucket("�ν�") << endl;   //��ȡkey���ڵ�Ͱ��

	//key�����ظ�
	m.insert(make_pair("����", "������"));
	cout << m.size() << endl;

	cout << m["����"] << endl;   //����value
	cout << m.size() << endl;
	//m["������"] = "������";
	//cout << m["������"] << endl;
	cout << m["³��"] << endl;
	cout << m.size() << endl;

	m.erase("³��");
	cout << m.size() << endl;

	m.clear();

}

void test_unordered_multimap() {
	unordered_multimap<string, string> m;
	//�����ֵ�Ե����ַ�ʽ
	m.insert(pair<string, string>("�ν�", "��ʱ��"));
	m.insert(pair<string, string>("����", "��ţ"));
	m.insert(pair<string, string>("�ֳ�", "����ͷ"));

	m.insert(make_pair("����", "����"));

	cout << m.size() << endl;
	cout << m.bucket_count() << endl;   //Ͱ�ĸ���
	cout << m.bucket_size(0) << endl;   //0��Ͱ�еĸ���
	cout << m.bucket("�ν�") << endl;   //��ȡkey���ڵ�Ͱ��

	//key�����ظ�
	m.insert(make_pair("����", "������"));
	cout << m.size() << endl;

	m.erase("³��");
	cout << m.size() << endl;

	m.clear();
}
*/

int main() {
	//test_unordered_multimap();
	//test_unordered_map();
	TestHashBucket();
	system("pause");
	return 0;
}