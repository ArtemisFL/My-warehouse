#include <iostream> 
#include <vector> 
#include <algorithm> 
using namespace std; 

//����Լ���������1�ͱ����Լ�� 
void divisorNum(int n, vector<int> &divNum) { 
	for (int i = 2; i <= sqrt(n); i++) { 
		if (n%i == 0) { 
			divNum.push_back(i); 
			//��ƽ����ʱ������һ����ҲҪ���� 
			if (n / i != i) 
				divNum.push_back(n / i); 
		}
	} 
}
int Jump(int N, int M) { 
	//����ĵ����stepNum��Ĳ�������ʼNΪ1������N��NΪ1�� 
	vector<int> stepNum(M + 1, 0); 
	stepNum[N] = 1; 
	for (int i = N; i < M; i++) { 
		//N������Լ������Ϊ�ӱ�������㿪ʼ���ߵ����� 
		vector<int> divNum; 
		//0��������㲻�ܵ� 
		if (stepNum[i] == 0) 
			continue; 
		//����������ߵĲ���������divNum�������� 
		divisorNum(i, divNum); 
		for (int j = 0; j < divNum.size(); j++) { 
			//��λ��i�����ܵ���ĵ�Ϊ stepNum[divNum[j]+i] 
			if ((divNum[j] + i) <= M && stepNum[divNum[j] + i] != 0) 
				stepNum[divNum[j] + i] = min(stepNum[divNum[j] + i], stepNum[i] + 1); 
			else if ((divNum[j] + i) <= M) 
				stepNum[divNum[j] + i] = stepNum[i] + 1; 
		} 
	}
	if (stepNum[M] == 0) 
		return -1; 
	else
		//��ʼ��ʱ�����һ��������Ҫ��1 
		return stepNum[M] - 1;
}

int Function(unsigned int n) { 
	n = (n & 0x55555555) + ((n >> 1) & 0x55555555); 
	n = (n & 0x33333333) + ((n >> 2) & 0x33333333); 
	n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f); 
	n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff); 
	n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff); 
	return n; 
}

int main() { 
	cout<<Function(197) << endl;
	/*int n, m; 
	cin >> n >> m; 
	cout << Jump(n, m) << endl;*/ 
	return 0; 
}