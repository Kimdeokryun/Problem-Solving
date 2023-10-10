#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int n;
int add[] = {1, -1, 1, -1};
string dir[] = { "<-", "->", "ㅗ", "ㅜ"};
int max_result = 0;

void solve(int count, vector<vector<int>> board, vector<vector<int>> ways)
{
	if (count == 5) { 
		// 최대값 찾아서 max_result 갱신하기.
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (board[i][j] > max_result) 
				{
					max_result = board[i][j];
				}
			}
		}
		return; 
	}

	vector<vector<int>> temp = board;
	queue<int> q_repo;
	queue<int> q;

	int start_y;
	int start_x;
	int x;
	int y;
	int q_pop = 0;



	for (int way = 0; way < 4; way++)
	{
		start_y = ways[way][0];
		start_x = ways[way][1];

		if (way < 2) 
		{
			for (int i = start_y; i < n; i++)
			{
				// q에 저장하기. 0이 아닌 값.
				x = start_x;
				while (x >= 0 && x < n) 
				{
					if (board[i][x] != 0) { 
						q.push(board[i][x]); 
					}
					x += add[way];
				}

				// q에서 찾아서 board에 다시 넣기
				x = start_x;
				while (x >= 0 && x < n)
				{
					if (q.empty()) { board[i][x] = 0; }
					else {
						q_pop = q.front();
						q.pop();
						if (q.empty()) { board[i][x] = q_pop; }
						else {
							if (q_pop == q.front()) 
							{
								board[i][x] = q_pop*2;
								q.pop();
							}
							else 
							{
								board[i][x] = q_pop;
							}
						}
					}

					x += add[way];
				}

			}
		}
		else 
		{
			for (int j = start_x; j < n; j++)
			{
				// q에 저장하기. 0이 아닌 값
				y = start_y;
				while (y >= 0 && y < n)
				{
					if (board[y][j] != 0) { q.push(board[y][j]); }
					y += add[way];
				}

				// q에서 찾아서 board에 다시 넣기
				y = start_y;
				while (y >= 0 && y < n)
				{
					if (q.empty()) { board[y][j] = 0; }
					else {
						q_pop = q.front();
						q.pop();
						if (q.empty()) { board[y][j] = q_pop; }
						else {
							if (q_pop == q.front())
							{
								board[y][j] = q_pop * 2;
								q.pop();
							}
							else
							{
								board[y][j] = q_pop;
							}
						}
					}
					y += add[way];
				}

			}
		}

		solve(count+1, board, ways);
		board = temp;
	}

}


int main() 
{
	cin >> n;
	vector<vector<int>> board(n, vector<int>(n));
	vector<vector<int>> ways = { {0,0}, {0,n-1}, {0,0}, {n-1,0} };

	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}

	solve(0, board, ways);

	cout << max_result << "\n";
	return 0;
}