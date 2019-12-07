 #include <string> 
#include <iostream> 
#include <vector> 
#include<algorithm>
using namespace std; 

int minDistance(string word1, string word2) { 
	// word��մ�֮��ı༭����Ϊword�ĳ��� 
	if (word1.empty() || word2.empty()) { 
		return max(word1.size(), word2.size()); 
	}
	int len1 = word1.size(); 
	int len2 = word2.size(); 
	// F(i,j)��ʼ�� 
	vector<vector<int> > f(1 + len1, vector<int>(1 + len2, 0));
	for (int i = 0; i <= len1; ++i) { 
		f[i][0] = i; 
	}
	for (int i = 0; i <= len2; ++i) { 
		f[0][i] = i; 
	}
	for (int i = 1; i <= len1; ++i) {
		for (int j = 1; j <= len2; ++j) { 
			// F(i,j) = min { F(i-1,j��+1, F(i,j-1) +1, F(i-1,j-1) + //(w1[i]==w2[j]?0:1) } 
			// �ж�word1�ĵ�i���ַ��Ƿ���word2�ĵ�j���ַ���� 
			if (word1[i - 1] == word2[j - 1]) { 
				f[i][j] = 1 + min(f[i][j - 1], f[i - 1][j]); 
				// �ַ���ȣ�F(i-1,j-1)�༭���벻�� 
				f[i][j] = min(f[i][j], f[i - 1][j - 1]); 
			}
			else {
				f[i][j] = 1 + min(f[i][j - 1], f[i - 1][j]); 
				// �ַ�����ȣ�F(i-1,j-1)�༭���� + 1 
				f[i][j] = min(f[i][j], 1 + f[i - 1][j - 1]); 
			} 
		} 
	}
	return f[len1][len2]; 
} 
int main(){ 
	string a,b; 
	while(cin>>a>>b) 
		cout<<minDistance(a, b)<<endl; 
	system("pause");
	return 0; 
}

#if 0
class A {
public: 
	void print() { 
		cout << "A:print()"; 
	} 
};
class B: public A {
public: 
	void print() { 
		cout << "B:print()"; 
	} 
};
class C: public B {
public: 
	void print() { 
		A:: print(); 
	} 
};
int main() { 
	C b;
	b.print();
	system("puase");
	return 0;
}
#endif

#if 0
#include<iostream>
#include<string>
using namespace std;

unsigned int count = 0xffffffff;
//s2��Զ���ڵ���s1,�����ǲ��룬ֻ����ɾ��s2
void Count(const char* s1, const char* s2, int ret, int s2Ret) {
	if (*s1 == '\0'&&*s2 == '\0')
	{
		if (ret < coun)
			coun = ret;
		return;
	}
	if (*s1 == '\0' || *s2 == '\0')
		return;
	while (*s1 == *s2&&*s1 != '\0'&&*s2 != '\0') {
		++s1;
		++s2;
	}
	//�滻
	if (*s1 != '\0'&&*s2 != '\0')
		Count(s1 + 1, s2 + 1, ret + 1��s2Ret);

	//ɾ��
	if (*s2 != '\0'&&s2Ret > 0)
		Count(s1, s2 + 1, ret + 1, s2Ret - 1);
}
int main() {
	string s1, s2;
	while (cin >> s1 >> s2) {
		if (s1.size() > s2.size()) {
			string tmp = s1;
			s1 = s2;
			s2 = tmp;
		}
		count = 0xffffffff;
		Count(s1.c_str(), s2.c_str(), 0, s2.size() - s1.size());
		cout << count << endl;
	}
	return 0;
}
#endif 