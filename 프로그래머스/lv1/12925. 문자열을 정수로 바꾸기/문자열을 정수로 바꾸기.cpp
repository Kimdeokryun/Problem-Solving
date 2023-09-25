#include <string>
#include <vector>

using namespace std;

int transform(string s) {
	return stoi(s);
}

int solution(string s) {
	int answer = 0;

	if (s[0] == '-')
	{
		answer = transform(s.substr(1, s.size()));
		answer *= -1;
	}
	else {
		answer = transform(s);
	}

	return answer;
}