#include "stdc++.h"
using namespace std;
// Binary search (note boundaries in the caller) 
int CeilIndex(std::vector<int>& v, int l, int r, int key)
{
	while (r - l > 1) {
		int m = l + (r - l) / 2;
		if (v[m] >= key)
			r = m;
		else
			l = m;
	}

	return r;
}

int LongestIncreasingSubsequenceLength(std::vector<int>& v)
{
	if (v.size() == 0)
		return 0;

	std::vector<int> tail(v.size(), 0);
	int length = 1; // always points empty slot in tail 

	tail[0] = v[0];
	for (size_t i = 1; i < v.size(); i++) {

		// new smallest value 
		if (v[i] < tail[0])
			tail[0] = v[i];

		// v[i] extends largest subsequence 
		else if (v[i] > tail[length - 1])
			tail[length++] = v[i];

		// v[i] will become end candidate of an existing 
		// subsequence or Throw away larger elements in all 
		// LIS, to make room for upcoming grater elements 
		// than v[i] (and also, v[i] would have already 
		// appeared in one of LIS, identify the location 
		// and replace it) 
		else
			tail[CeilIndex(tail, -1, length - 1, v[i])] = v[i];
	}

	return length;
}

// Complete the longestIncreasingSubsequence function below.
int longestIncreasingSubsequence(vector<int> arr) {
	
	return LongestIncreasingSubsequenceLength(arr);
	/*assert(arr.size() != 0);
	vector<vector<int>> lis;
	lis.resize(arr.size());
	/*for (auto v : lis)
	{
		v = 0;
	}
	
	lis[0].push_back(arr[0]);
	//fill(lis.begin(), lis.end(), 1);
	for (int i = 1; i < arr.size(); i++)
	{
		//int curMax = 1, tempmax= 1;
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j] && lis[i].size() < (lis[j].size() + 1))
			{

				lis[i] = lis[j];
			}
		}
		lis[i].push_back(arr[i]);
	}
	int result = 0;
	for (auto v : lis)
	{
		if (v.size() > result)
			result = v.size();
	}
	return result;*/
}

int main()
{
	//ofstream fout(getenv("OUTPUT_PATH"));

	int n;
	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	vector<int> arr(n);

	for (int i = 0; i < n; i++) {
		int arr_item;
		cin >> arr_item;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		arr[i] = arr_item;
	}

	int result = longestIncreasingSubsequence(arr);

	//fout << result << "\n";

	//fout.close();

	return 0;
}
