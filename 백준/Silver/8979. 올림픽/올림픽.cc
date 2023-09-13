#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	map<string, int> medal_table;

	int num, gold, silver, bronze;
	int result = 1;
	bool cal = false;
	string temp;

	for (int i = 0; i < N; i++) 
	{
		cin >> num >> gold >> silver >> bronze;
		string s = to_string(gold) + " " + to_string(silver) + " " + to_string(bronze);
		medal_table[s]++;
		if (num == K) { temp = s; }
	}

	for (auto element : medal_table) 
	{
		if (cal) { result += element.second; }
		if (element.first == temp) { cal = true; }
	}

	cout << result<< endl;
}