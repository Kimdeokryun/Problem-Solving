#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> T(n + 1);
	vector<int> P(n + 1);
	vector<int> dp(n + 2);

	for (int i = 1; i <= n; i++) 
	{
		cin >> T[i] >> P[i];
	}

	int deadline;
	for (int i = n; i > 0; i--) {
		deadline = i + T[i];
		if (deadline > n + 1) 
		{
			dp[i] = dp[i + 1];
		}
		else {
			dp[i] = max(dp[i + 1], dp[deadline] + P[i]);
		}
	}

	cout << dp[1];

}