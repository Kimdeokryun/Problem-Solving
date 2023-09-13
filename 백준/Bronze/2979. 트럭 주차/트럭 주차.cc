#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int A, B, C;
	cin >> A >> B >> C;
	int time[101] = {0,};

	int result = 0;
	for (int i = 0; i< 3; i++)
	{
		int arrival, department;
		cin >> arrival >> department;
		for (int j = arrival; j < department; j++) 
		{
			time[j] += 1;
		}
	}

	for (int i = 0; i <= 100; i++)
	{
		if (time[i] == 0) { continue; }
		else if (time[i] == 1) { result += time[i] * A; }
		else if (time[i] == 2) { result += time[i] * B; }
		else if (time[i] == 3) { result += time[i] * C; }
	}

	cout << result;

	return 0;
}