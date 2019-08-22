#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:        
	int minDistance(string word1, string word2) {     
		// word��մ�֮��ı༭����Ϊword�ĳ���        
		if (word1.empty() || word2.empty()) {   
			return word1.size() > word2.size() ? word1.size() : word2.size();
	}
	 int len1 = word1.size();      
	 int len2 = word2.size(); 
	 // F(i,j)��ʼ��       
	 vector<vector<int>>f(1 + len1, vector<int>(1 + len2, 0));
	 for (int i = 0; i <= len1; ++i) { 
		 f[i][0] = i; 
	 } 
	 for (int i = 0; i <= len2; ++i) {  
		 f[0][i] = i; 
	 }
	 for (int i = 1; i <= len1; ++i) {
		  for (int j = 1; j <= len2; ++j) {       
			  // F(i,j) = min { F(i-1,j��+1, F(i,j-1) +1, F(i-1,j-1) +(w1[i]==w2[j]? 0:1) }                
			  // �ж�word1�ĵ�i���ַ��Ƿ���word2�ĵ�j���ַ����            
			  if (word1[i - 1] == word2[j - 1]) {    
				  f[i][j] = 1 + (f[i][j - 1] < f[i - 1][j] ? f[i][j - 1] : f[i - 1][j]);
				  // �ַ���ȣ�F(i-1,j-1)�༭���벻��     
				  f[i][j] = f[i][j] < f[i - 1][j - 1] ? f[i][j] : f[i - 1][j - 1];
			  } 
			  else {             
				  f[i][j] = 1 + (f[i][j - 1] < f[i - 1][j] ? f[i][j - 1] : f[i - 1][j]);
				  // �ַ�����ȣ�F(i-1,j-1)�༭���� + 1        
				  f[i][j] = f[i][j] < 1 + f[i - 1][j - 1] ? f[i][j] : 1 + f[i - 1][j - 1];
			  }
		  }
	 }
	 for (int i = 1; i <= len1; i++)
	 {
		 for (int j = 1; j <= len2; j++)
		 {
			 printf("%d ", f[i][j]);
		 }
		 printf("\n");
	 }
	   return f[len1][len2];
  }
};
int main()
{
	Solution s;
	cout << s.minDistance("leetcode", "aleelcard") << endl;




	system("pause");
	return 0;
}