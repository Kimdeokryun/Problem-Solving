#include<iostream>
#include<vector>
#include<string.h>
#include<math.h>
using namespace std;

vector<string> tools(4);
bool turn[4];
int dir_type[4];

void setting_turn(int idx, int dir)
{
	switch (idx) 
	{
	case 0:
		turn[0] = true;
		dir_type[0] = dir;

		if (tools[0][2] != tools[1][6])
		{
			turn[1] = true;
			dir_type[1] = dir * -1;

			if (tools[1][2] != tools[2][6])
			{
				turn[2] = true;
				dir_type[2] = dir;

				if (tools[2][2] != tools[3][6])
				{
					turn[3] = true;
					dir_type[3] = dir * -1;
				}
			}
		}
		break;

	case 1:
		turn[1] = true;
		dir_type[1] = dir;

		if (tools[0][2] != tools[1][6])
		{
			turn[0] = true;
			dir_type[0] = dir * -1;
		}

		if (tools[1][2] != tools[2][6])
		{
			turn[2] = true;
			dir_type[2] = dir * -1;

			if (tools[2][2] != tools[3][6])
			{
				turn[3] = true;
				dir_type[3] = dir;
			}
		}
		break;

	case 2:
		turn[2] = true;
		dir_type[2] = dir;

		if (tools[1][2] != tools[2][6])
		{
			turn[1] = true;
			dir_type[1] = dir * -1;

			if (tools[0][2] != tools[1][6])
			{
				turn[0] = true;
				dir_type[0] = dir;
			}
		}

		if (tools[2][2] != tools[3][6])
		{
			turn[3] = true;
			dir_type[3] = dir * -1;
		}
		break;

	default:
		turn[3] = true;
		dir_type[3] = dir;

		if (tools[2][2] != tools[3][6])
		{
			turn[2] = true;
			dir_type[2] = dir * -1;

			if (tools[1][2] != tools[2][6])
			{
				turn[1] = true;
				dir_type[1] = dir * 1;

				if (tools[0][2] != tools[1][6])
				{
					turn[0] = true;
					dir_type[0] = dir * -1;
				}
			}
		}		
		break;
	}
}

void turning(int idx, int type)
{
	string temp_str = tools[idx];
	char temp;
	if (type == 1)	// 시계 방향 회전
	{
		temp = temp_str[7];
		for (int i = 7; i > 0; i--) 
		{
			temp_str[i] = temp_str[i-1];
		}
		temp_str[0] = temp;
	}
	else // 반시계 방향 회전
	{
		temp = temp_str[0];
		for (int i = 0; i < 7; i++)
		{
			temp_str[i] = temp_str[i + 1];
		}
		temp_str[7] = temp;
	}

	tools[idx] = temp_str;
}



int main() 
{
	for (int i = 0; i < 4; i++) 
	{
		cin >> tools[i];
	}

	int k;
	cin >> k;

	int number, dir;

	for (int i = 0; i < k; i++) 
	{
		cin >> number >> dir;
		number -= 1;

		memset(turn, false, sizeof(turn));
		memset(dir_type, 0, sizeof(dir_type));
		// turning 정하기
		setting_turn(number, dir);

		for (int idx = 0; idx < 4; idx++)
		{
			if (turn[idx]) 
			{
				turning(idx, dir_type[idx]);
			}
		}
	}

	int result = 0;
	for (int i = 0; i < 4; i++)
	{
		if (tools[i][0] == '1') //12시 S극
		{
			result += (1 * pow(2, i));	// 1번은 1점, 2번은 2점, 3번은 4점 ,4번은 8점 (2의 i승)
		}
	}

	cout << result << endl;

}