# include <iostream>
# include <stack>
# include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int repeat, plat;
	int num, plat_num;
	cin >> repeat >> plat;
	
	int result = 0;
	vector<stack<int>> melody(7);

	for (int i = 0; i < repeat; i++) 
	{
		cin >> num >> plat_num;

		if (!melody[num].empty() && melody[num].top() > plat_num)
		{
			while (!melody[num].empty() && melody[num].top() > plat_num) {
				melody[num].pop();
				result++;
			}
		}

		if (melody[num].empty() || melody[num].top() < plat_num)
		{
			result++;
			melody[num].push(plat_num);
		}
	}

	cout << result << endl;
	return 0;
}