#include<iostream>
#include<vector>

using namespace std;

int n, m;
int max_result;
bool visited[500][500];
int paper[500][500];
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1};

void solve(int count, int x, int y, int result)
{
	if (count == 4) 
	{
		if (max_result < result) { max_result = result; }
		return;
	}

	for (int i = 0; i < 4; i++) 
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m)
		{
			continue;
		}
		if (visited[nx][ny]) { continue; }

		visited[nx][ny] = true;
		solve(count + 1, nx, ny, result + paper[nx][ny]);
		visited[nx][ny] = false;
	}

	if (count == 1) 
	{
		int other_result;
		if (x - 1 >= 0 && x < n && y >= 0 && y + 2 < m) // ㅗ 모양
		{
			other_result = result + paper[x][y + 1] + paper[x][y + 2] + paper[x - 1][y + 1];
			if (other_result > max_result) { max_result = other_result; }
		}
		if (x >= 0 && x + 2 < n && y >= 0 && y + 1 < m)	// ㅏ 모양
		{
			other_result = result + paper[x + 1][y] + paper[x + 2][y] + paper[x + 1][y + 1];
			if (other_result > max_result) { max_result = other_result; }
		}
		if (x >= 0 && x + 1 < n && y >= 0 && y + 2 < m)	// ㅜ 모양
		{
			other_result = result + paper[x][y + 1] + paper[x][y + 2] + paper[x + 1][y + 1];
			if (other_result > max_result) { max_result = other_result; }
		}
		if (x - 1 >= 0 && x + 1 < n && y >= 0 && y + 1 < m)	// ㅓ 모양
		{
			other_result = result + paper[x + 1][y + 1] + paper[x][y + 1] + paper[x - 1][y + 1];
			if (other_result > max_result) { max_result = other_result; }
		}
	}
}

int main() 
{

	cin >> n >> m;

	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < m; j++)
		{
			cin >> paper[i][j];
		}
	}
	
	max_result = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			visited[i][j] = true;
			solve(1, i, j, paper[i][j]);
			visited[i][j] = false;
		}
	}
	
	cout << max_result << "\n";

	return 0;
}