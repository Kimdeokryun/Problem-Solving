#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string N, temp; cin >> N;
	int size = N.size();
	int n_num = stoi(N);

	int f_num = 0, temp_num;
	for (int i = 1; i < n_num; i++)
	{
		temp = to_string(i);
		temp_num = i;
		for (int j = 0; j < temp.size(); j++)
		{
			temp_num += temp[j] - '0';
		}
		if (temp_num == n_num) { f_num = i; break; }
	}

	cout << f_num << endl;

}