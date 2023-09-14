#include <iostream>
#include <vector>

using namespace std;

int hate[100001];
bool visited[100001];

int dfs(int start)
{
	visited[start] = true;	// 방문 처리

	int next = hate[start];	// 좋아하는 다음 채널 불러옴

	if (next == 0) { return 0; }	// 다음 채널이 0이라면 모두가 현재 채널을 좋아한다는 뜻	0 return

	if (visited[next]) { return - 1; }	// 다음 채널이 방문했었다면 dom이므로 -1 return

	int count = dfs(next);	// 다음 채널 탐색

	return count == -1 ? -1 : count + 1;	// count가 -1이 아니라면  count+1 return
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, P;
	cin >> N >> M >> P;

	int a, b;

	for (int i = 0; i < N; i++) 
	{
		cin >> a >> b;
		if (hate[b] == 0) { hate[b] = a; }
	}

	cout << dfs(P) << endl;
	return 0;
}