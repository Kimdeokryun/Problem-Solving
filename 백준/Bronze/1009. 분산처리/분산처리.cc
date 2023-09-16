#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	int a, b;
	int temp;

	for (int i = 0; i < T; i++) 
	{
		cin >> a >> b;
		temp = 1;

		for (int j = 0; j < b; j++) {
			temp = (temp * a) % 10;
		}
		if (temp == 0) {
			cout << 10 << endl;
		}
		else {
			cout << temp << endl;
		}
	}
	return 0;
}