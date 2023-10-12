#include<iostream>
#include<vector>

using namespace std;

int min_result;
int n, m, h;

vector<vector<int>> map(31, vector<int>(11));

void solve(int add_num) 
{
	int x, y;
	
	for (int i = 1; i <= n; i++) 
	{
		x = 1; y = i;
		while (x <= h) 
		{
			if (map[x][y] == 0) { x += 1; }
			else if (map[x][y] == 1) { x += 1; y += 1; }
			else { x += 1; y -= 1;  }
		}
		if (y != i) { return; }
	}

	if (min_result > add_num) { min_result = add_num; }
}



int main() 
{

	cin >> n >> m >> h;

	int x, y;

 	for (int i = 0; i < m; i++) 
	{
		cin >> x >> y;

		map[x][y] = 1;
		map[x][y + 1] = 2;
	}

	min_result = 4;

	solve(0);

	for (int first_x = 1; first_x <= h && min_result > 1; first_x++)
	{
		for (int first_y = 1; first_y <= n && min_result > 1; first_y++)
		{
			if (map[first_x][first_y] != 0 || map[first_x][first_y + 1] != 0) { continue; }
			map[first_x][first_y] = 1;
			map[first_x][first_y + 1] = 2;

			solve(1);

			for (int second_x = 1; second_x <= h && min_result > 2; second_x++)
			{
				for (int second_y = 1; second_y <= n && min_result > 2; second_y++)
				{
					if (map[second_x][second_y] != 0 || map[second_x][second_y + 1] != 0) { continue; }
					map[second_x][second_y] = 1;
					map[second_x][second_y + 1] = 2;

					solve(2);
					for (int third_x = 1; third_x <= h && min_result > 3; third_x++)
					{
						for (int third_y = 1; third_y <= n && min_result > 3; third_y++)
						{
							if (map[third_x][third_y] != 0 || map[third_x][third_y + 1] != 0) { continue; }
							map[third_x][third_y] = 1;
							map[third_x][third_y + 1] = 2;

							solve(3);

							map[third_x][third_y] = 0;
							map[third_x][third_y + 1] = 0;
						}
					}

					map[second_x][second_y] = 0;
					map[second_x][second_y + 1] = 0;
				}
			}

			map[first_x][first_y] = 0;
			map[first_x][first_y + 1] = 0;
		}
	}

	if (min_result == 4) { min_result = -1; }

	cout << min_result << "\n";

	return 0;
}