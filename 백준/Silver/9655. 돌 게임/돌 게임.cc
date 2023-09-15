#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;	// 돌 개수
	cin >> N;

	int dp[1001];	// 게임 횟수

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= N; i++) 
	{
		dp[i] = min(dp[i - 1] + 1, dp[i - 3] + 1);
	}

	if (dp[N] % 2 == 0) { cout << "CY" << endl; }
	else { cout << "SK" << endl; }

	return 0;
}