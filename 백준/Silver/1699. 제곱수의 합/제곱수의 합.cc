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

	vector<int> dp(N + 1, 0);

	for (int i = 1; i <= N; i++)
	{
		dp[i] = i;
		for (int j = 1; j * j <= i; j++) 
		{
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}

	cout << dp[N] << endl;

	return 0;
}