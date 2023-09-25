#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
	bool answer = true;

	int p_num = 0;
	int y_num = 0;

	string temp = "";

	for (int i = 0; i < s.size(); i++) {
		temp += tolower(s[i]);
		if (temp[i] == 'p') { p_num++; }
		else if (temp[i] == 'y') { y_num++; }
	}

	if (p_num != y_num) answer = false;

	return answer;
}