#include<iostream>
#include<vector>
#include<map>
using namespace std;

int T, n;
vector<vector<vector<char>>> cube(6, vector<vector<char>>(3, vector<char>(3)));

void clockwise(int num)
{
	char temp = cube[num][0][0];
	cube[num][0][0] = cube[num][2][0];
	cube[num][2][0] = cube[num][2][2];
	cube[num][2][2] = cube[num][0][2];
	cube[num][0][2] = temp;

	temp = cube[num][0][1];
	cube[num][0][1] = cube[num][1][0];
	cube[num][1][0] = cube[num][2][1];
	cube[num][2][1] = cube[num][1][2];
	cube[num][1][2] = temp;
}

void U()
{
	vector<vector<char>> temp = cube[5];
	cube[5] = cube[0];
	cube[0] = cube[4];
	cube[4] = cube[1];
	cube[1] = temp;

	clockwise(1); clockwise(1);
	clockwise(4); clockwise(4);
	clockwise(2);
	clockwise(3); clockwise(3); clockwise(3);
}

void F()
{
	vector<vector<char>> temp = cube[2];
	cube[2] = cube[5];
	cube[5] = cube[3];
	cube[3] = cube[4];
	cube[4] = temp;

	clockwise(2);
	clockwise(4);
	clockwise(3);
	clockwise(5);
	clockwise(1); clockwise(1); clockwise(1);
	clockwise(0);
}

void L()
{
	// 0 -> 2 -> 1 -> 3
	vector<vector<char>> temp = cube[0];
	for (int i = 0; i < 3; i++)
	{
		cube[0][i][0] = cube[3][i][0];
		cube[3][i][0] = cube[1][i][0];
		cube[1][i][0] = cube[2][i][0];
		cube[2][i][0] = temp[i][0];
	}
	clockwise(4);
}
void R()
{
	// 0 -> 3 -> 1 -> 2
	vector<vector<char>> temp = cube[0];
	for (int i = 0; i < 3; i++)
	{
		cube[0][i][2] = cube[2][i][2];
		cube[2][i][2] = cube[1][i][2];
		cube[1][i][2] = cube[3][i][2];
		cube[3][i][2] = temp[i][2];
	}
	clockwise(5);
}

void init_cube()	// 큐브 초기화
{
	int cube_number = 0;
	char color_index[6] = { 'w', 'y', 'r', 'o', 'g', 'b' };
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				cube[i][j][k] = color_index[cube_number / 9];
				cube_number++;
			}
		}
	}
}

int main(void)
{
	cin >> T;
	string str;

	while (T--)
	{
		init_cube();

		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> str;
			int k = 1;		// 회전 횟수
			if (str[1] == '-') k = 3;	// 반시계 방향은  시계방향을 3번 회전 하면 된다.

			if (str[0] == 'U')
			{
				U();
				for (int j = 0; j < k; j++) R();
				for (int j = 0; j < 3; j++) U();
			}
			else if (str[0] == 'D')
			{
				U();
				for (int j = 0; j < k; j++) L();
				for (int j = 0; j < 3; j++) U();
			}
			else if (str[0] == 'F')
			{
				F();
				for (int j = 0; j < k; j++) L();
				for (int j = 0; j < 3; j++) F();
			}
			else if (str[0] == 'B')
			{
				F();
				for (int j = 0; j < k; j++) R();
				for (int j = 0; j < 3; j++) F();
			}
			else if (str[0] == 'L')
			{
				for (int j = 0; j < k; j++) L();
			}
			else if (str[0] == 'R')
			{
				for (int j = 0; j < k; j++) R();
			}
		}

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
				cout << cube[0][i][j];
			cout << '\n';
		}
	}
	return 0;
}