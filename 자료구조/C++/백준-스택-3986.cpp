# include <iostream>
# include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int words;
	cin >> words;

	string input;

	int success, result = 0;

	for (int i = 0; i < words; i++)
	{
		cin >> input;
		stack<char> str;
		success = 1;
		str.push(input[0]);
		for (int idx = 1; idx < input.length(); idx++)
		{
			if (!str.empty() && str.top() == input[idx])
			{
				str.pop();
			}
			else
			{
				str.push(input[idx]);
			}
		}
		if (str.empty()) { result++; }
	}

	cout << result << endl;
	return 0;
}