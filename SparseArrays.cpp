#include "stdc++.h"

using namespace std;

// Complete the matchingStrings function below.
vector<int> matchingStrings(vector<string> strings, vector<string> queries) {
	vector<int> result;
	assert(strings.size() != 0);
	assert(queries.size() != 0);
	for (auto q : queries)
	{
		int tCount = 0;
		for (auto s : strings)
		{
			if (s == q)
				tCount++;
		}
		result.push_back(tCount);
	}

	return result;

}

int main()
{
	ofstream fout("test");//(getenv("OUTPUT_PATH"));

	int strings_count;
	cin >> strings_count;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	vector<string> strings(strings_count);

	for (int i = 0; i < strings_count; i++) {
		string strings_item;
		getline(cin, strings_item);

		strings[i] = strings_item;
	}

	int queries_count;
	cin >> queries_count;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	vector<string> queries(queries_count);

	for (int i = 0; i < queries_count; i++) {
		string queries_item;
		getline(cin, queries_item);

		queries[i] = queries_item;
	}

	vector<int> res = matchingStrings(strings, queries);

	for (int i = 0; i < res.size(); i++) {
		fout << res[i];

		if (i != res.size() - 1) {
			fout << "\n";
		}
	}

	fout << "\n";

	fout.close();

	return 0;
}
