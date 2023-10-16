#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int r, c;
vector<string> board(21);
map<char, int> check;
queue <pair<int, int>> q;

int max_result;

void solve(int x, int y, int count) 
{
	if (max_result < count) { max_result = count; }

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= r || ny >= c)
		{
			continue;
		}
		if (check[board[nx][ny]] != 0) { continue; }
		check[board[nx][ny]] = 1;
		solve(nx, ny, count + 1);
		check[board[nx][ny]] = 0;
	}

}

int main() 
{

	cin >> r >> c;

	for (int i = 0; i < r; i++) 
	{
		cin >> board[i];
	}

	max_result = 0;
	check[board[0][0]] = 1;
	
	solve(0,0,1);

	cout << max_result << "\n";

	return 0;
}