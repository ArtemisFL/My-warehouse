#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> printMatrix(vector<vector<int> > matrix) {
		vector<int> arr;
		if (matrix.size() == 0 || matrix[0].size() == 0)
			return arr;
		int up = 0, down = matrix.size() - 1;
		int left = 0, right = matrix[0].size() - 1;
		while (left <= right && up <= down)
		{
			//����
			for (int i = left; i <= right; ++i)
				arr.push_back(matrix[up][i]);
			++up;
			//����
			for (int i = up; i <= down && left <= right; ++i)
				arr.push_back(matrix[i][right]);
			--right;
			//����
			for (int i = right; i >= left && up <= down; --i)
				arr.push_back(matrix[down][i]);
			--down;
			//����
			for (int i = down; i >= up && left <= right; --i)
				arr.push_back(matrix[i][left]);
			++left;
		}
		return arr;
	}
};

int main()
{
	vector<vector<int>> arr{{1,2,3,4,5,6,7,8,9},
		{1,2,3,4,5,6,7,8,9},
		{1,2,3,4,5,6,7,8,9},
		{1,2,3,4,5,6,7,8,9},
		{1,2,3,4,5,6,7,8,9},
		{1,2,3,4,5,6,7,8,9}
	};
	Solution sa;
	sa.printMatrix(arr);
	system("pause");
	return 0;
}

