#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
	vector<int> answer;
	int num;

	while (n > 0) {
		num = n % 10;
		n /= 10;
		answer.push_back(num);
	}

	return answer;
}