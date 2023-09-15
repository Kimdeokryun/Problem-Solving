#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	vector<int> T_num(1001);

	for (int i = 1; i < 1001; i++) 
	{
		T_num[i] = T_num[i - 1] + i;
	}

	int result_num;
	int check;
	bool loop;

	for (int i = 0; i < T; i++) 
	{
		cin >> result_num;

		check = 0;
		loop = true;

		for (int i = 1; i <= 50 && loop; i++)
		{
			for (int j = 1; j <= 50 && loop; j++)
			{
				for (int k = 1; k <= 50 && loop; k++)
				{
					if (T_num[i] + T_num[j] + T_num[k] == result_num) { loop = false; check = 1; }
				}
			}
		}

		cout << check << endl;
	}

	return 0;
}