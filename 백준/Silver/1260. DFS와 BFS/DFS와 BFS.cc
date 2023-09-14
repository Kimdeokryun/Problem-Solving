#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

vector<int> graph[1001];
bool visited[1001];
queue<int> q;

void bfs(int x)
{
	q.push(x);
	visited[x] = 1;

	// 큐가 빌 때까지 반복
	while (!q.empty()) {
		// 큐에서 하나의 원소를 뽑아 출력
		x = q.front();
		q.pop();
		cout << x << " ";
		// 해당 원소와 연결된, 아직 방문하지 않은 원소들을 큐에 삽입
		for (int i = 0; i < graph[x].size(); i++) {
			int y = graph[x][i];
			if (!visited[y]) {
				q.push(y);
				visited[y] = visited[x] + 1;
			}
		}
	}
}

void dfs(int start) 
{
	// 방문한 정점이라면 return
	if (visited[start]) { return; }

	// 방문 표시
	visited[start] = 1;
	// 출력
	cout << start << " ";

	// 다음 정점 탐색 및 재귀
	for (int i = 0; i < graph[start].size(); i++) {
		int y = graph[start][i];
		dfs(y);
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, V;
	int x, y;
	cin >> N >> M >> V;

	for (int i = 0; i < M; i++) 
	{
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	// 정점이 작은 것 부터 방문해야하므로 정렬
	for (int i = 0; i < 1001; i++) { sort(graph[i].begin(), graph[i].end()); }
	// dfs 먼저 수행
	dfs(V);
	cout << endl;
	// visited 초기화
	memset(visited, 0, 1001* sizeof(bool));
	// bfs 수행
	bfs(V);
	
	return 0;
}
