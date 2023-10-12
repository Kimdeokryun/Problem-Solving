#include<iostream>
#include<vector>

using namespace std;


int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0, -1, 0 };

class dragon 
{
public:
	int x;	// x좌표
	int y;	// y좌표
	int d;	// 시작 방향
	int g;	// 세대

	void init(int x, int y, int d, int g) 
	{
		this->x = x;
		this->y = y;
		this->d = d;
		this->g = g;
	}
};

vector<vector<int>> map(101, vector<int>(101));
vector<dragon> dragon_curve;

int main() 
{
	int n;
	cin >> n;

	int x, y, d, g;
	for (int i = 0; i < n; i++) 
	{
		cin >> x >> y >> d >> g;
		dragon dragon_input;
		dragon_input.init(x, y, d, g);
		dragon_curve.push_back(dragon_input);
	}

	for (int i = 0; i < n; i++)
	{
		vector<int> curve;

		y = dragon_curve[i].x;
		x = dragon_curve[i].y;
		d = dragon_curve[i].d;
		g = dragon_curve[i].g;

		map[x][y] = 1;

		int nx = x + dx[d];
		int ny = y + dy[d];

		map[nx][ny] = 1;
		curve.push_back(d);
		
		for (int idx = 0; idx < g; idx++) 
		{
			int len = curve.size();
			for (int curve_idx = len-1; curve_idx >= 0; curve_idx--)
			{
				int next_d = curve[curve_idx] + 1;
				if (next_d == 4) { next_d = 0; }
				
				nx = nx + dx[next_d];
				ny = ny + dy[next_d];

				map[nx][ny] = 1;
				curve.push_back(next_d);

			}
		}
	}
	int result = 0;

	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (map[i][j] == 1)
			{
				if (map[i + 1][j] == 1 && map[i][j + 1] == 1 && map[i + 1][j + 1] == 1)
				{
					result++;
				}
			}
		}
	}
	cout << result << "\n";

	return 0;
}