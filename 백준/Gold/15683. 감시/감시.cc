#include<iostream>
#include<vector>

using namespace std;

int n, m;
int min_result;
vector<pair<int, int>> cctv_pos;
vector<int> cctv;
int cctv_num;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int cctv_for1[4] = { 0,1,2,3 };
int cctv_for2[2][2] = { {0,1},{2,3} };
int cctv_for3[4][2] = { {0,3}, {1,3}, {0,2}, {1,2} };
int cctv_for4[4][3] = { {0,2,3}, {0,1,3}, {0,1,2}, {1,2,3} };
int cctv_for5[4] = { 0, 1, 2, 3 };

void solve(int idx, vector<vector<int>> office)
{
	if (idx == cctv_num)	// cctv를 모두 확인 한 경우.
	{
		int result = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (office[i][j] == 0) { result++; }
			}
		}
		if (result < min_result) { min_result = result; }
		return;
	}

	int x = cctv_pos[idx].first;
	int y = cctv_pos[idx].second;
	int cctv_type = cctv[idx];

	vector<vector<int>> temp = office;

	switch (cctv_type) 
	{
	case 1:															// 1번 카메라
		
		for (int i = 0; i < 4; i++)									// 상, 하, 좌, 우 차례대로 한 번씩.
		{
			int nx = x, ny = y;
			int dir = cctv_for1[i];
			while (!(nx < 0 || ny < 0 || nx >= n || ny >= m))
			{
				if (office[nx][ny] == 6) { break; }
				if (office[nx][ny] == 0) { office[nx][ny] = -1; }
				nx += dx[dir];
				ny += dy[dir];
			}

			solve(idx + 1, office);
			office = temp;		//cctv 감시 초기화
		}

		break;
	case 2:															// 2번 카메라
		
		for (int i = 0; i < 2; i++)									// (상, 하), (좌, 우) 차례대로 한 번씩
		{
			int nx = x, ny = y;
			int dir = cctv_for2[i][0];

			while (!(nx < 0 || ny < 0 || nx >= n || ny >= m))
			{
				if (office[nx][ny] == 6) { break; }
				if (office[nx][ny] == 0) { office[nx][ny] = -1; }
				nx += dx[dir];
				ny += dy[dir];
			}

			nx = x; ny = y;
			dir = cctv_for2[i][1];

			while (!(nx < 0 || ny < 0 || nx >= n || ny >= m))
			{
				if (office[nx][ny] == 6) { break; }
				if (office[nx][ny] == 0) { office[nx][ny] = -1; }
				nx += dx[dir];
				ny += dy[dir];
			}

			solve(idx + 1, office);
			office = temp;		//cctv 감시 초기화
		}
		break;
	case 3:																// 3번 카메라 (상, 우), (하, 우), (상, 좌), (하, 좌)
		for (int i = 0; i < 4; i++)
		{
			int nx = x, ny = y;
			int dir = cctv_for3[i][0];

			while (!(nx < 0 || ny < 0 || nx >= n || ny >= m))
			{
				if (office[nx][ny] == 6) { break; }
				if (office[nx][ny] == 0) { office[nx][ny] = -1; }
				nx += dx[dir];
				ny += dy[dir];
			}

			nx = x; ny = y;
			dir = cctv_for3[i][1];

			while (!(nx < 0 || ny < 0 || nx >= n || ny >= m))
			{
				if (office[nx][ny] == 6) { break; }
				if (office[nx][ny] == 0) { office[nx][ny] = -1; }
				nx += dx[dir];
				ny += dy[dir];
			}

			solve(idx + 1, office);
			office = temp;		//cctv 감시 초기화
		}
		break;
	case 4:																// 4번 카메라  (좌, 상, 우), (상, 하, 우), (상, 하, 좌), (좌, 하, 우)
		for (int i = 0; i < 4; i++)
		{

			int nx = x, ny = y;
			int dir = cctv_for4[i][0];

			while (!(nx < 0 || ny < 0 || nx >= n || ny >= m))
			{
				if (office[nx][ny] == 6) { break; }
				if (office[nx][ny] == 0) { office[nx][ny] = -1; }
				nx += dx[dir];
				ny += dy[dir];
			}

			nx = x; ny = y;
			dir = cctv_for4[i][1];

			while (!(nx < 0 || ny < 0 || nx >= n || ny >= m))
			{
				if (office[nx][ny] == 6) { break; }
				if (office[nx][ny] == 0) { office[nx][ny] = -1; }
				nx += dx[dir];
				ny += dy[dir];
			}

			nx = x; ny = y;
			dir = cctv_for4[i][2];

			while (!(nx < 0 || ny < 0 || nx >= n || ny >= m))
			{
				if (office[nx][ny] == 6) { break; }
				if (office[nx][ny] == 0) { office[nx][ny] = -1; }
				nx += dx[dir];
				ny += dy[dir];
			}

			solve(idx + 1, office);
			office = temp;		//cctv 감시 초기화
		}
		break;
	default:															// 5번 카메라		(상, 하, 좌, 우 한 번씩)
		
		int nx = x, ny = y;
		int dir = cctv_for5[0];

		while (!(nx < 0 || ny < 0 || nx >= n || ny >= m))					// 상 이동
		{
			if (office[nx][ny] == 6) { break; }
			if (office[nx][ny] == 0) { office[nx][ny] = -1; }
			nx += dx[dir];
			ny += dy[dir];
		}

		nx = x; ny = y;
		dir = cctv_for5[1];

		while (!(nx < 0 || ny < 0 || nx >= n || ny >= m))					// 하 이동
		{
			if (office[nx][ny] == 6) { break; }
			if (office[nx][ny] == 0) { office[nx][ny] = -1; }
			nx += dx[dir];
			ny += dy[dir];
		}

		nx = x; ny = y;
		dir = cctv_for5[2];	

		while (!(nx < 0 || ny < 0 || nx >= n || ny >= m))					// 좌 이동
		{
			if (office[nx][ny] == 6) { break; }
			if (office[nx][ny] == 0) { office[nx][ny] = -1; }
			nx += dx[dir];
			ny += dy[dir];
		}

		nx = x; ny = y;
		dir = cctv_for5[3];

		while (!(nx < 0 || ny < 0 || nx >= n || ny >= m))					// 우 이동
		{
			if (office[nx][ny] == 6) { break; }
			if (office[nx][ny] == 0) { office[nx][ny] = -1; }
			nx += dx[dir];
			ny += dy[dir];
		}

		solve(idx + 1, office);
		office = temp;		//cctv 감시 초기화
		break;
	}


}


int main() 
{
	cin >> n >> m;
	vector<vector<int>> office(8, vector<int>(8));

	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < m; j++)
		{
			cin >> office[i][j];
			if (1 <= office[i][j] && office[i][j] <= 5) 
			{
				cctv_pos.push_back(make_pair(i, j));
				cctv.push_back(office[i][j]);
			}
		}
	}
	
	min_result = 64;
	cctv_num = cctv.size();

	solve(0,  office);

	cout << min_result << "\n";

	return 0;
}