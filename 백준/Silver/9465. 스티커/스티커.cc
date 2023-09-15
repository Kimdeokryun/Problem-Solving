#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, n;
	int result;
	cin >> T;

	while (T > 0) 
	{
		T--;
		cin >> n;
		result = 0;
		vector<vector<int>> score_list(2, vector<int>(n+1));
		vector<vector<int>> dp(2, vector<int>(n+1,0));

		for (int i = 1; i <= n; i++) 
		{
			cin >> score_list[0][i];
		}
		for (int i = 1; i <= n; i++)
		{
			cin >> score_list[1][i];
		}

		dp[0][1] = score_list[0][1];
		dp[1][1] = score_list[1][1];
		dp[0][2] = score_list[0][2] + dp[1][1];
		dp[1][2] = score_list[1][2] + dp[0][1];

		for (int i = 3; i <= n; i++) 
		{
			dp[0][i] = score_list[0][i] + max(dp[1][i - 1], dp[1][i - 2]);
			dp[1][i] = score_list[1][i] + max(dp[0][i - 1], dp[0][i - 2]);
		}
		result = max(dp[0][n], dp[1][n]);

		cout << result << endl;
	}

	return 0;
}