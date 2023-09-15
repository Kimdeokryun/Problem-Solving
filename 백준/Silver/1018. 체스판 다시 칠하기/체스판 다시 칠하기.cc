#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	string line;
	vector<vector<char>> board(N, vector<char>(M));
	
	int result = 64;

	for (int i = 0; i < N; i++) 
	{
		cin >> line;
		for (int j = 0; j < M; j++) 
		{
			board[i][j] = line[j];
		}
	}

	for (int x = 0; x <= N-8; x++)
	{
		for (int y = 0; y <= M-8; y++)
		{
			int even_W = 0;
			int even_B = 0;

			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					char temp = board[i + x][j + y];

					if ((i + j) % 2 == 0) 
					{
						if (temp == 'W') { even_B++; }
						else { even_W++; }
					}
					else 
					{
						if (temp == 'W') { even_W++; }
						else { even_B++; }
					}
				}
			}
			result = min(result, min(even_W, even_B));
		}
	}

	cout << result << endl;

	return 0;
}