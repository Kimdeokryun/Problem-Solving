#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	long long dp[91];

	dp[1] = 1;
	dp[2] = 1;

	for (int i = 3; i <= N; i++) 
	{
		dp[i] = dp[i - 2] + dp[i - 1];
	}

	cout << dp[N] << endl;

	return 0;
}