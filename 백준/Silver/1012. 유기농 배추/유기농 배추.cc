#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 상하좌우 이동을 위한 배열
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

void bfs(int x, int y, int m, int n, vector<vector<int>>& graph, vector<vector<bool>>& visited)
{
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	visited[x][y] = true;
    
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
        // 상하좌우 이동
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
            // 이동 가능한 부분 체크
			if (nx >= 0 && nx < m && ny >= 0 && ny < n && graph[nx][ny] == 1 && !visited[nx][ny]) {
				q.push(make_pair(nx, ny));
				visited[nx][ny] = true;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	int M, N, K;
	int x, y;

	cin >> T;

	for (T; T > 0; T--)
	{
		cin >> M >> N >> K;
        // 2중 벡터 선언
		vector<vector<int>> graph(M, vector<int>(N, 0));
		vector<vector<bool>> visited(M, vector<bool>(N, false));

		for (int i = 0; i < K; i++)
		{
			cin >> x >> y;
			graph[x][y] = 1;
		}

		int count = 0;
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (graph[i][j] == 1 && !visited[i][j])
				{
					bfs(i, j, M, N, graph, visited);
					count++;
				}
			}
		}
		cout << count << endl;
	}

	return 0;
}