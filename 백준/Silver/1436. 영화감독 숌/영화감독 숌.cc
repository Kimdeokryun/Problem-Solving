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

	int N; cin >> N;
	int find = 0, result = 0;
	string str;
	for (int i = 666; find < N; i++) 
	{
		str = to_string(i);
		if (str.find("666") != -1) { find++; result = i; }
	}

	cout << result << endl;
}