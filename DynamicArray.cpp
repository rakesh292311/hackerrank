#include "stdc++.h"

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the dynamicArray function below.
vector<int> dynamicArray(int n, vector<vector<int>> queries) {
	vector<vector<int>> my_data;
	vector<int> result;
	int last_answer = 0;
	if (n == 0)
		return result;
	my_data.resize(n);
	for (auto v : queries)
	{
		int r = (v[1] ^ last_answer) % n;
		if (v[0] == 1)
		{
			my_data[r].push_back(v[2]);
		}
		else if (v[0] == 2)
		{
			int index = v[2] % (my_data[r].size());
			last_answer = my_data[r][index];
			result.push_back(last_answer);

		}
	}
	
	return result;
		

}

int main()
{
	ofstream fout;// (getenv("OUTPUT_PATH"));

	string nq_temp;
	getline(cin, nq_temp);

	vector<string> nq = split(rtrim(nq_temp));

	int n = stoi(nq[0]);

	int q = stoi(nq[1]);

	vector<vector<int>> queries(q);

	for (int i = 0; i < q; i++) {
		queries[i].resize(3);

		string queries_row_temp_temp;
		getline(cin, queries_row_temp_temp);

		vector<string> queries_row_temp = split(rtrim(queries_row_temp_temp));

		for (int j = 0; j < 3; j++) {
			int queries_row_item = stoi(queries_row_temp[j]);

			queries[i][j] = queries_row_item;
		}
	}

	vector<int> result = dynamicArray(n, queries);

	for (int i = 0; i < result.size(); i++) {
		fout << result[i];

		if (i != result.size() - 1) {
			fout << "\n";
		}
	}

	fout << "\n";

	fout.close();

	return 0;
}

string ltrim(const string &str) {
	string s(str);

	s.erase(
		s.begin(),
		find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
		);

	return s;
}

string rtrim(const string &str) {
	string s(str);

	s.erase(
		find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
		s.end()
		);

	return s;
}

vector<string> split(const string &str) {
	vector<string> tokens;

	string::size_type start = 0;
	string::size_type end = 0;

	while ((end = str.find(" ", start)) != string::npos) {
		tokens.push_back(str.substr(start, end - start));

		start = end + 1;
	}

	tokens.push_back(str.substr(start));

	return tokens;
}
