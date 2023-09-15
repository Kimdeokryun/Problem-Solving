#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> dp(n, 0);
	vector<int> list(n);
	
	for (int i = 0; i < n; i++) { cin >> list[i]; }

	dp[0] = list[0];
	int result = dp[0];
	for (int i = 1; i < n; i++) 
	{
		dp[i] = list[i];
		if (dp[i] < dp[i - 1] + list[i]) 
		{
			dp[i] = dp[i - 1] + list[i];
		}
		result = max(result, dp[i]);
	}

	cout << result << endl;

	return 0;
}