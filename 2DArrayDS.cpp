// 2D Array - DS
//#include <bits/stdc++.h>
#include <vector>
#include <iostream>

using namespace std;

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {
	int m = arr.size();
	if (m == 0)
		return 0;
	int n = arr[0].size();
	int i, j;
	int temp_sum, max_sum;
	temp_sum = max_sum = INT_MIN;
	for (i = 0; i + 2 < m; i++)
	{
		for (j = 0; j + 2 < n; j++)
		{
			temp_sum = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 1] + arr[i + 2][j] + arr[i + 2][j + 1] + arr[i + 2][j + 2];
			if (max_sum < temp_sum)
				max_sum = temp_sum;
		}
	}
	return max_sum;

}

int main()
{
	//ofstream fout(getenv("OUTPUT_PATH"));

	vector<vector<int>> arr(6);
	for (int i = 0; i < 6; i++) {
		arr[i].resize(6);

		for (int j = 0; j < 6; j++) {
			cin >> arr[i][j];
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	int result = hourglassSum(arr);

	//fout << result << "\n";

	//fout.close();

	return 0;
}
