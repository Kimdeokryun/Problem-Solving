#include<iostream>
#include<vector>
#include<queue>
#include<deque>
using namespace std;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
int n;

bool inRange(int x, int y) {
	return (x >= 0 && x < n && y >= 0 && y < n);
}

int Turn_Direction(int d, char c)
{
	if (c == 'L')
	{
		if (d == 0) return 3;
		else if (d == 1) return 2;
		else if (d == 2) return 0;
		else if (d == 3) return 1;
	}
	else if (c == 'D')
	{
		if (d == 0) return 2;
		else if (d == 1) return 3;
		else if (d == 2) return 1;
		else if (d == 3) return 0;
	}
}

int main() 
{
	
	int k;
	cin >> n;
	cin >> k;

	vector<vector<int>> board(n, vector<int>(n));
	deque<pair<int, int>> snake;
	queue<pair<int, char>> moves;

	int row, col;
	for (int i = 0; i < k; i++) 
	{
		cin >> row >> col;
		board[row-1][col-1] = 1;
	}

	int l;
	cin >> l;

	int x;
	char c;
	for (int i = 0; i < l; i++)
	{
		cin >> x >> c;
		moves.push(make_pair(x, c));
	}

	bool keep = true;
	bool make = false;

	int current_time = 0;
	int current_dir = 0;

	int current_x = 0;
	int current_y = 0;

	snake.push_back(make_pair(current_x, current_y));
	board[current_y][current_x] = 2;

	while (true) 
	{
		// 움직일 때, 머리 위치만 현재 방향에 맞춰서 움직여주면 됨.   그리고 deque를 활용하여 현재 이동 거리를 조정. ()

		current_time++;
		int move_x = current_x + dx[current_dir];
		int move_y = current_y + dy[current_dir];
		
		if (!inRange(move_y, move_x) || board[move_y][move_x] == 2) {
			break;
		}
		else if (board[move_y][move_x] == 0) {
			board[move_y][move_x] = 2;
			board[snake.back().second][snake.back().first] = 0;
			snake.pop_back();
			snake.push_front(make_pair(move_x, move_y));
		}
		else if (board[move_y][move_x] == 1) {	//사과가 있다면. 
			board[move_y][move_x] = 2;
			snake.push_front(make_pair(move_x, move_y));
		}

		if (!moves.empty())
		{
			if (current_time == moves.front().first) {
				// 다음 방향 결정.
				if (moves.front().second == 'L') { current_dir = Turn_Direction(current_dir, 'L'); }
				else { current_dir = Turn_Direction(current_dir, 'D'); }
				moves.pop();
			}
		}

		current_x = move_x;
		current_y = move_y;
	}

	cout << current_time << '\n';

	return 0;
}