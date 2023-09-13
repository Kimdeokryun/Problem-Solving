#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int P;
	cin >> P;
	vector<int> line;
	int T, count, h;
	for (int i = 0; i < P; i++) 
	{
		count = 0;
		line = {};
		cin >> T;
		for (int j = 0; j < 20; j++) 
		{
			cin >> h;
			for (int k = 0; k < j; k++) 
			{
				if (line[k] > h) { count++; }
			}
			line.push_back(h);
		}
		cout << T << " " << count << endl;
	}
}