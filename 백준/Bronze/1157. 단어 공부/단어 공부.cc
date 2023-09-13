#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	cin >> str;
	map<char, int> alpha_count;
	int maxval = 0;
	char result = '?';

	for (char c : str) 
	{
		// 대문자로 변환
		char upper = toupper(c);
		alpha_count[upper]++;
	}

	// 루프로 max 값 찾기.
	for (auto element : alpha_count)
	{
		// 새로운 max값 찾았다면 result 값 초기화
		if (element.second > maxval) 
		{
			maxval = element.second;
			result = element.first;
		}
		// max값과 같다면 result ?로 초기화
		else if (element.second == maxval) 
		{
			result = '?';
		}
	}

	cout << result << endl;
	return 0;
}