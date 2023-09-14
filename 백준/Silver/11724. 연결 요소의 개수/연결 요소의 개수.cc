#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[1001];
bool visited[1001];

void dfs(int start)
{
	if (visited[start]) { return; }
	
	visited[start] = true;

	for (int i = 0; i < graph[start].size(); i++) 
	{
		dfs(graph[start][i]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	int u, v;
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	int count = 0;

	for (int i = 1; i <= N; i++)
	{
		if (visited[i]) { continue; }
		else 
		{
			dfs(i);
			count++;
		}
	}

	cout << count << endl;

	return 0;
}