#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n, m;
vector<vector<int>> map(8, vector<int>(8));
vector<vector<int>> temp;

vector<pair<int, int>> virus;

int max_result;

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0,0, -1, 1 };


void spreadvirus(int x, int y)	// 바이러스 퍼짐
{
	temp[x][y] = 2;

	for (int dir = 0; dir < 4; dir++)
	{
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (nx < 0 || nx >= n || ny < 0 || ny >= m)
			continue;

		if (temp[nx][ny] != 0)
			continue;

		spreadvirus(nx, ny);
	}
}


void solve() 
{
	temp = map;		// 현재 map 복사
	int virus_len = virus.size();

	for (int i = 0; i < virus_len; i++)	// 현재 바이러스 위치.
	{
		spreadvirus(virus[i].first, virus[i].second);		// dfs 바이러스 퍼짐
	}

	int result = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (temp[i][j] == 0) // 바이러스 위치
			{
				result++;
			}
		}
	}

	if (max_result < result) { max_result = result; }  // 안전 영역 최대 값.
}

int main() 
{

	cin >> n >> m;

	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 2) 
			{
				virus.push_back(make_pair(i, j));	// 바이러스 위치 저장
			}
		}
	}

	max_result = 0;

	for (int first_x = 0; first_x < n; first_x++)		//첫번째 벽
	{
		for (int first_y = 0; first_y < m; first_y++)
		{
			if (map[first_x][first_y] != 0) {
				continue;
			}

			map[first_x][first_y] = 1;

			for (int second_x = 0; second_x < n; second_x++)	//두번째 벽
			{
				for (int second_y = 0; second_y < m; second_y++)
				{
					if (map[second_x][second_y] != 0) {
						continue;
					}

					map[second_x][second_y] = 1;

					for (int third_x = 0; third_x < n; third_x++)	//세번째 벽
					{
						for (int third_y = 0; third_y < m; third_y++)
						{
							if (map[third_x][third_y] != 0) {
								continue;
							}

							map[third_x][third_y] = 1;

							solve();

							map[third_x][third_y] = 0;		// 세번째 벽 위치 초기화
						}

					}
					map[second_x][second_y] = 0;	// 두번째 벽 위치 초기화
				}

			}
			map[first_x][first_y] = 0;	// 첫번째 벽 위치 초기화
		}
	}

	cout << max_result << "\n";
	return 0;
}