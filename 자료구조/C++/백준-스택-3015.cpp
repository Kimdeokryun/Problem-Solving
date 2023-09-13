# include <iostream>
# include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, now, cnt;
	cin >> N;
	stack<pair<int, int>> stand;
	long result = 0;

	for (int i = 0; i < N; i++) 
	{
		cin >> now;
		cnt = 1;
		while (!stand.empty() && stand.top().first < now) 
		{
			result += stand.top().second;
			stand.pop();
		}

		if (!stand.empty()) 
		{
			if (stand.top().first == now) 
			{
				result += stand.top().second;
				cnt = (stand.top().second + 1);
				if (stand.size() >= 2) 
				{
					result++;
				}
				stand.pop();
			}
			else { 
				result++;
			}
		}
		stand.push(make_pair(now, cnt));
	}

	cout << result << endl;
	return 0;
}