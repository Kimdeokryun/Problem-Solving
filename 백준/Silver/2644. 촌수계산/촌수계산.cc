#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> graph[101];
int visited[101];

queue<int> q;
int p1, p2;

void bfs() 
{
	q.push(p1);
	//visited[p1] = true;

	// 큐가 빌 때까지 반복
	while (!q.empty()) {
		// 큐에서 하나의 원소를 뽑아 출력
		int x = q.front();
		q.pop();

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


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	int x, y;

	cin >> n;
	cin >> p1 >> p2;
	cin >> m;

	for (int i = 0; i < m; i++) 
	{
		cin >> x >> y;
		// 부모와 자식 모두 양방향으로 설정
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	bfs();

	if (visited[p2] == 0) { visited[p2] = -1; }
	cout << visited[p2] << endl;

	return 0;
}