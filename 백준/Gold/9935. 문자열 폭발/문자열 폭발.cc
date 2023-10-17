#include <iostream>
#include <vector>

using namespace std;

int main() 
{
	string str;
	cin >> str;

	string boom_str;
	cin >> boom_str;

	int str_len = str.size();
	int boom_str_len = boom_str.size();
	vector<char> str_stack;

	string result = "";

	for (int i = 0; i < str_len; i++)
	{
		str_stack.push_back(str[i]);
		int stack_size = str_stack.size();
		if (stack_size >= boom_str_len)
		{
			string temp = "";
			for (int idx = 0; idx < boom_str_len; idx++)
			{
				if (str_stack[stack_size - boom_str_len + idx] == boom_str[idx]) { temp += boom_str[idx]; }
				else { break; }
			}

			if (temp == boom_str) {
				for (int idx = 0; idx < boom_str_len; idx++)
				{
					str_stack.pop_back();
				}
			}
		}
		
	}


	int str_stack_size = str_stack.size();
	if (str_stack_size == 0) { result = "FRULA"; }
	else 
	{
		for (int i = 0; i < str_stack_size; i++) 
		{ 
			result += str_stack[i];
		}
	}
		
	cout << result << "\n";

	return 0;
}