#include<iostream>
#include<vector>
#include<queue>
#include<cstdlib>

using namespace std;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int n, l, r;
int result;
vector<vector<int>> map;
vector<vector<int>> visited;
bool change;

void solve(int x, int y) 
{
	if (visited[x][y] == 1) { return; }

	queue<pair<int, int>> q;
	vector<pair<int, int>> boundary;

	int count_people = map[x][y];
	boundary.push_back(make_pair(x, y));

	q.push(make_pair(x, y));
	visited[x][y] = 1;

	while (!q.empty()) 
	{
		int temp_x = q.front().first, temp_y = q.front().second;
		q.pop();

		int nx, ny;
		
		for (int dir = 0; dir < 4; dir++) 
		{
			nx = temp_x + dx[dir];
			ny = temp_y + dy[dir];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n) { continue; }

			if (visited[nx][ny]) { continue; }

			int temp_number = map[temp_x][temp_y];
			int n_number = map[nx][ny];

			int diff = abs(temp_number-n_number);
			if (l <= diff && diff <= r) 
			{
				visited[nx][ny] = 1;
				count_people += map[nx][ny];
				boundary.push_back(make_pair(nx, ny));
				q.push(make_pair(nx, ny));
			}
		}
	}

	int b_size = boundary.size();
	if (b_size > 1)
	{
		change = true;
		int move_people = count_people / b_size;
		for (int i = 0; i < b_size; i++) 
		{
			int vx = boundary[i].first;
			int vy = boundary[i].second;

			map[vx][vy] = move_people;
		}
	}
}


int main() 
{
	cin >> n >> l >> r;

	map.assign(n, vector<int>(n));

	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}

	result = 0;
	change = true;

	while (change)
	{
		change = false; // 갱신

		visited.assign(n, vector<int>(n));

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				solve(i, j);
			}
		}
		if (change) { result++; }
	}

	cout << result << "\n";
	return 0;
}