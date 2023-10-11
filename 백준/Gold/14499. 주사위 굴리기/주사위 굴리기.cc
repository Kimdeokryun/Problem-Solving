#include<iostream>
#include<vector>
using namespace std;

int dx[] = { 0, 0, 0, -1, 1 };
int dy[] = { 0, 1, -1, 0, 0 };
int dice[7] = { 0, };

void roll(int d)
{
	int d1, d2, d3, d4, d5, d6;
	d1 = dice[1], d2 = dice[2], d3 = dice[3];
	d4 = dice[4], d5 = dice[5], d6 = dice[6];

	if (d == 1) // 동쪽
	{
		dice[1] = d4;
		dice[4] = d6;
		dice[6] = d3;
		dice[3] = d1;
	}
	else if (d == 2) // 서쪽
	{
		dice[4] = d1;
		dice[6] = d4;
		dice[3] = d6;
		dice[1] = d3;
	}
	else if (d == 3) // 북쪽
	{
		dice[1] = d5;
		dice[2] = d1;
		dice[6] = d2;
		dice[5] = d6;
	}
	else if (d == 4) // 남쪽
	{
		dice[5] = d1;
		dice[1] = d2;
		dice[2] = d6;
		dice[6] = d5;
	}
}

int main() 
{
	int n, m;
	int x, y, k;
	cin >> n >> m >> x >> y >> k;
	vector<vector<int>> map(n, vector<int>(m));

	vector<int> commander(k);
	int command;

	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < k; i++)
	{
		cin >> commander[i];
	}

	for (int i = 0; i < k; i++)
	{		
		int nx = x + dx[commander[i]];
		int ny = y + dy[commander[i]];
		command = commander[i];

		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

		roll(command);
		if (map[nx][ny] == 0) { 
			map[nx][ny] = dice[6]; 
		}
		else
		{
			dice[6] = map[nx][ny];
			map[nx][ny] = 0;
		}

		cout << dice[1] << "\n";

		x = nx;
		y = ny;
	}

	return 0;
}