#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;

	int num = 0;

	for (long long i = x; num++ < n; i += x) {
		answer.push_back(i);
	}

	return answer;
}