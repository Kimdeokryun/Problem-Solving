#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = 0;

    long long x = sqrt(n);

    if (pow(x, 2) == n)
    {
        answer = pow(x + 1, 2);
    }
    else { answer = -1; }

    return answer;
}
