#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int dy[3] = { -1, 0, 1 };
int N, M;

int solve(int x, int y, int last, vector<vector<int>>& map)
{
	if (x == N) return 0;

	int min_val = 700;

	for (int i = 0; i < 3; i++) 
	{
		if (i == last) continue;
		if (y + dy[i] < 0 || y + dy[i] >= M) continue;

		min_val = min(min_val, solve(x + 1, y + dy[i], i, map) + map[x][y]);
	}
	return min_val;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	int result = 700;
	vector<vector<int>> map(N+1, vector<int>(M+1));

	for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j < M; j++) 
		{
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < M; i++)
	{
		result = min(result, solve(0,i,-1, map));
	}

	cout << result << endl;

	return 0;
}