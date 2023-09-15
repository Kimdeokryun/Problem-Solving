#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int A;
	cin >> A;
	vector<int> A_list(A+1);
	vector<int> dp(A+1,0);

	for (int i = 1; i <= A; i++) { cin >> A_list[i]; }

	int result = 0;

	for (int i = 1; i <= A; i++) 
	{
		dp[i] = A_list[i];
		for (int j = 1; j < i; j++) 
		{
			if (A_list[j] < A_list[i] && dp[i] < dp[j] + A_list[i]) 
			{
				dp[i] = dp[j] + A_list[i];
			}
		}
		result = max(result, dp[i]);
	}

	cout << result << endl;

	return 0;
}