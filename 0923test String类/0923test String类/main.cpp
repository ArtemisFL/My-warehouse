#include<iostream>
#include<string>
using namespace std;

void test1()
{
	string s1;
	string s2("hello");
	string s3(10, '$');
	string s4(s3);
	cin >> s1;
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;

}
void test2()
{
	string s("hello!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
	/*cout << s.size() << endl;
	cout << s.length() << endl;
	cout << s.capacity() << endl;
	cout << s.empty() << endl;
	s.clear();
	cout << s.size() << endl;
	cout << s.length() << endl;
	cout << s.capacity() << endl;
	cout << s.empty() << endl;*/

	/*s.reserve(15);
	cout << s.size() << endl;
	cout << s.length() << endl;
	cout << s.capacity() << endl;
	cout << s.empty() << endl;
	s.reserve(25);
	cout << s.size() << endl;
	cout << s.length() << endl;
	cout << s.capacity() << endl;
	cout << s.empty() << endl;
	s.reserve(45);
	cout << s.size() << endl;
	cout << s.length() << endl;
	cout << s.capacity() << endl;
	cout << s.empty() << endl;*/
	s.reserve(85);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	s.reserve(45);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	s.reserve(25);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	s.reserve(14);
	cout << s.size() << endl;
	cout << s.capacity() << endl; //newcapacity > oldcapacity(string��ɿռ��С)���ռ�����--->�����ı�(����������С >= newCapacity)����ЧԪ�ظ�������
								// newcapacity < oldcapacity(string��ɿռ��С)���ռ���С���ú���ֱ�ӷ��� ����newcapacity < 15
								// ע�⣺ֻ�ı�������С������ı���ЧԪ�ظ���������ı�Ŀռ��СС������ЧԪ�ش�С�򲻸ı�ռ��С
	/*s.resize(20, 'c');
	cout << s << endl;
	s.resize(25);//Ĭ����\0���
	cout << s << endl;*/

}
void test3()
{
	string s("hello");
	cout << s[0] << endl;
	s[0] = 'H';
	// ���Խ��---assert����
	//cout << s[10] << endl;

	cout << s.at(2) << endl;
	s.at(2) = 'L';

	// ���Խ��---�׳�out_of_range�쳣
	//cout << s.at(10) << endl;
	const char *ss = s.c_str();
	cout << ss << endl;
}
void test4()
{
	string s1;
	s1.push_back('I');
	s1 += "Love ";
	s1.append("You ");
	s1.append(3, '!');
	cout << s1 << endl;
}
void test5()
{
	string s("12345");
	int ret = atoi(s.c_str());//�ַ���ת����
	cout << ret << endl;
}
void test6()
{
	string s = ("hello world!");
	size_t pos = s.find(' ');
	cout << string::npos << endl;
	if (pos != string::npos)
	{
		cout << ' ' << " is in s" << pos << endl;
	}
	pos = s.find("world");
	if (pos != string::npos)
	{
		cout << "world" << " is in s" << pos << endl;
	}

	// ��ȡ�ļ��ĺ�׺ - 20190923.cpp.cpp
	string ss("20190923.cpp.cpp");
	pos = ss.rfind('.') + 1;

	string filepox = ss.substr(pos);
	cout << filepox << endl;
}
void test7()
{
	string s("ADsdvsdvxz");
	auto it = s.begin();
	while (it != s.end())
		cout << *it++<<"   ";
}
void reversestring(string& s)
{
	 	char* begin = (char*)s.c_str();
	 	char* end = begin + s.size() - 1;
	 	while (begin < end)
	 	{
	 		swap(*begin, *end);
	 		begin++;
	 		end--;
	 	}

	reverse(s.begin(), s.end());//�����ַ���
}

int main()
{
	string s("abcdef");
	reversestring(s);
	////test7();
	//test2();
	//test1();


	system("pause");
	return 0;
}