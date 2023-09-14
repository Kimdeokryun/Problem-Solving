#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//시간초과로 dfs는 사용하지 X
/*
void dfs(vector<string>& map, vector<vector<bool>>& visited, int x, int y, int& minDist, int count) {
    int N = map.size();
    int M = map[0].size();

    // 도착점에 도달한 경우
    if (x == N - 1 && y == M - 1) {
        minDist = min(minDist, count);
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < N && ny >= 0 && ny < M && map[nx][ny] == '1' && !visited[nx][ny]) {
            visited[nx][ny] = true;
            dfs(map, visited, nx, ny, minDist, count+1);
            visited[nx][ny] = false;
        }
    }
}
*/

int dx[] = { -1, 1, 0, 0 }; // 상하좌우 이동을 위한 배열
int dy[] = { 0, 0, -1, 1 };

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> map(N, vector<int>(M, 0));
    vector<vector<int>> dist(N, vector<int>(M, 0));
    vector<vector<bool>> visited(N, vector<bool>(M, false));

    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < M; j++) {
            map[i][j] = str[j] - '0';
        }
    }

    /*  dfs사용
    int minDist = 10001; // 최단 거리를 저장할 변수
    visited[0][0] = true; // 시작점 방문 표시
    dfs(map, visited, 0, 0, minDist, 1);
    cout << minDist << endl;
    */

    queue<pair<int, int>> q;

    q.push({ 0, 0 });
    visited[0][0] = true;
    dist[0][0]++;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if ( (nx >= 0 && nx < N) && (ny >= 0 && ny < M) && (map[nx][ny] == 1 && !visited[nx][ny] )) {
                q.push({ nx, ny });
                visited[nx][ny] = true;
                dist[nx][ny] = dist[x][y] + 1;
            }
        }
    }

    cout << dist[N-1][M-1] << endl;

    return 0;
}