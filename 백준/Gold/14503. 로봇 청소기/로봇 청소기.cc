#include<iostream>
#include<vector>

using namespace std;

int n, m;
vector<vector<int>> room(50, vector<int>(50));

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int result;

void solve(int x, int y, int d) 
{
	if (room[x][y] == 0) {// 현재 칸 청소
		room[x][y] = -1;
		result++;
	}

	bool check = false;

	for (int dir = 0; dir < 4; dir++)
	{
		int check_x = x + dx[dir];
		int check_y = y + dy[dir];
		if (0 <= check_x && 0 <= check_y && check_x < n && check_y < m) 
		{
			if (room[check_x][check_y] == 0) check = true;
		}
	}

	if (check) // 현재칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우
	{
		d -= 1;						// 반시계 방향 90도 회전 후
		if (d < 0) { d += 4; }
		int nx = x + dx[d];			// 바라보는 방향으로 한 칸 전진.
		int ny = y + dy[d];

		if (0 <= nx && 0 <= ny && nx < n && ny < m)
		{
			if (room[nx][ny] == 0)		// 전진 가능
			{
				solve(nx, ny, d);
			}
		}	

		solve(x, y, d); // 전진 불가능  (방향만 전환)
	}
	else  // 현재칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우
	{	
		int nx = x - dx[d];			// 바라보는 방향에서 한 칸 후진.
		int ny = y - dy[d];

		if (nx < 0 || ny < 0 || nx >= n || ny >= m || room[nx][ny] == 1) { cout << result << "\n"; exit(0); }	// 후진 불가능

		solve(nx, ny, d); // 후진 가능.
	}
}


int main() 
{
	cin >> n >> m;

	int r, c, d;	
	cin >> r >> c >> d; // d == 0 북쪽 , d == 1 동쪽,  d == 2 남쪽,  d == 3 서쪽
	
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < m; j++)
		{
			cin >> room[i][j];
		}
	}

	solve(r, c, d);

	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << room[i][j] << " ";
		}
		cout << endl;
	}


	cout << result << "\n";

	return 0;

}