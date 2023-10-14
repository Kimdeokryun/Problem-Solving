#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;

int n;
vector<vector<int>> map(21, vector<int>(21));
bool visit[21][21];

bool eat;
int shark_x, shark_y;
int shark_size;
int eat_count;
int time_result;

//상 좌 하 우   순으로
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

void bfs();

int main() 
{
	cin >> n;

	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 9)		// 아기 상어 위치
			{
				map[i][j] = 0;
				shark_x = i;
				shark_y = j;
			}
		}
	}

	bool stop = false;		// 값 초기화
	eat_count = 0;
	shark_size = 2;
	time_result = 0;

	while (!stop) 
	{
		memset(visit, false, sizeof(visit));

		bfs();

		if (eat) 
		{
			eat = false;
			eat_count+=1;
			map[shark_x][shark_y] = 0;	// 먹은 물고기 삭제
			if (eat_count == shark_size) { shark_size += 1; eat_count = 0; }
		}
		else 
		{
			stop = true;
		}
	}

	cout << time_result << "\n";
	return 0;

}

void bfs() 
{
	queue <pair<pair<int, int>, int>> q;	// first.first = x좌표, first.second = y좌표,  second는 시간좌표.
	q.push(make_pair(make_pair(shark_x, shark_y), 0));
	
	visit[shark_x][shark_y] = true;

	int temp_time;
	while (!q.empty()) 
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		int time = q.front().second;
	
		// 가장 위쪽을 먼저 그 다음 왼쪽을 우선적으로 먹는 것을 고려
		if (map[x][y] > 0 && map[x][y] < shark_size && temp_time == time) {
			if ((shark_x > x) || (shark_x == x && shark_y > y)) {		//위 고려 ||  좌측 고려
				shark_x = x; // 물고기를 먹은 상어 위치 저장
				shark_y = y;
				continue;		// 먹기 전 상어 이동부터.
			}
		}
		q.pop();	// 이전 위치 변경.

		for (int dir = 0; dir < 4; dir++) 
		{
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n || visit[nx][ny]) // out of range or visited
			{
				continue;
			}
			if (map[nx][ny] <= shark_size) // 지나가거나 먹을 수 있는 경우
			{
				if (map[nx][ny] > 0 && map[nx][ny] < shark_size && !eat) { //물고기를 먹을 수 있는 경우
					eat = true; // 한 마리 먹음
					shark_x = nx; // 먹을 물고기 위치로
					shark_y = ny;
					temp_time = time + 1; // 한 마리 먹는데 걸린 시간
					time_result += temp_time; // 총 시간에 추가
				}
				else { // 물고기를 못먹는 경우 이동만 (0이거나 상어와 같은 사이즈의 물고기)  (한 칸 이동마다 time이 1 증가)
					q.push(make_pair(make_pair(nx, ny), time + 1));
					visit[nx][ny] = true;
				}
			}
		}
	}
}