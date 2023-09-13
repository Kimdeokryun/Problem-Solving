# include <iostream>
# include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string input;
	cin >> input;

	int result = 0;
	stack<char> str;


	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] == '(')
		{
			str.push(input[i]);
		}
		else if (input[i] == ')' && input[i - 1] == '(')
		{
			str.pop();
			result += str.size();
		}
		else {
			result++;
			str.pop();
		}
	}

	cout << result << endl;
	return 0;
}