#include<iostream>
#include<vector>

using namespace std;

int n, l;
vector<vector<int>> map(100, vector<int>(100));

//vector<int> road;

int result;

void solve(int x, int y, int type, vector<int> road)	// type은 어느 방향에서 어디로 가는 지.
{
	if (type == 0) { // type에 따라 끝에 도달할 시.
		if (y == n - 1) { result++; return; }

		int ny = y+1;

		if (map[x][ny] == map[x][y]) 
		{
			road.push_back(ny);
			solve(x, ny, type, road);
		}
		else if(map[x][ny] - map[x][y] == 1)		// 지나갈 길이 더 높은 경우
		{
			int height = map[x][y];
			bool possible = true;
			for (int i = 0; i < l; i++) 
			{
				if (road.empty()) { possible = false; break; }
				int back_y = road.back();
				if(map[x][back_y] == height && back_y == (y - i))
				{
					road.pop_back();
				}
				else { possible = false; break; }
			}

			if (possible) {
				road.push_back(ny);
				solve(x, ny, type, road);
			}
		}
		else if (map[x][y] - map[x][ny] == 1) // 지나갈 길이 더 낮은 경우
		{
			int height = map[x][ny];
			bool possible = true;
			for (int i = 0; i < l; i++) 
			{
				if (i + ny >= n) { possible = false; break; }
				if (map[x][i + ny] != height) 
				{
					possible = false; break;
				}

			}
			if (possible) {
				solve(x, y+l, type, road);	//경사로 끝나는 위치에 도달
			}
		}
	}			
	else if (type == 1) {
		if (x == n-1) { result++;  return; }
		int nx = x+1;

		if (map[nx][y] == map[x][y])
		{
			road.push_back(nx);
			solve(nx, y, type, road);
		}
		else if (map[nx][y] - map[x][y] == 1) // 지나갈 길이 더 높은 경우
		{
			int height = map[x][y];
			bool possible = true;
			for (int i = 0; i < l; i++)
			{
				if (road.empty()) { possible = false; break; }
				
				int back_x = road.back();
				if (map[back_x][y] == height && back_x == (x - i))
				{
					road.pop_back();
				}
				else { possible = false; break; }
			}

			if (possible) {
				road.push_back(nx);
				solve(nx, y, type, road);
			}
		}
		else if(map[x][y] - map[nx][y] == 1) // 지나갈 길이 더 낮은 경우
		{
			int height = map[nx][y];
			bool possible = true;
			for (int i = 0; i < l; i++)
			{
				if (i + nx >= n) { possible = false; break; }
				if (map[i + nx][y] != height)
				{
					possible = false; break;
				}

			}
			if (possible) {
				solve(x+l, y, type, road);	//경사로 끝나는 위치에 도달
			}
		}
	}
}



int main() 
{

	cin >> n >> l;

	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}

	result = 0;

	for (int i = 0; i < n; i++)		// 왼쪽에서 오른쪽으로 가는 경우
	{
		vector<int> road;
		road.push_back(0);
		solve(i, 0, 0, road);
	}

	for (int i = 0; i < n; i++)		// 위에서 아래로 가는 경우
	{
		vector<int> road;
		road.push_back(0);
		solve(0, i, 1, road);
	}

	cout << result << "\n";

}