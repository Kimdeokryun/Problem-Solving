#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	vector<vector<int>> dp(N + 1, vector<int>(N+1, -1));

	for (int i = 0; i <= N; i++) 
	{
		for (int j = 0; j <= min(i, K); j++) 
		{
			if (j == 0 || i == j) { dp[i][j] = 1; }
			else { dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 10007; }
		}
	}

	cout << dp[N][K] << endl;

	return 0;
}