#include"BloomFilter.hpp"
#include<iostream>
using namespace std;

void TestBloomFilter() {
	BloomFilter<string, 100> bf;
	bf.insert("ŷ����");
	bf.insert("ŷ����");
	bf.insert("����");
	bf.insert("���ַ���");
	bf.insert("���");
	bf.insert("��̫��");

	cout << bf.size() << endl;
	if (bf.find("����"))
		cout << "�����Ǹ�����" << endl;
	else
		cout << "�����Ǹ�����" << endl;
	if (bf.find("���ַ���"))
		cout << "���ַ����Ǹ�����" << endl;
	else
		cout << "���ַ����Ǹ�����" << endl;
}

int main() {
	TestBloomFilter();
	system("pause");
	return 0;
}