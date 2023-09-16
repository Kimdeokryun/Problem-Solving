#include <iostream>

using namespace std;
int solution(int n)
{
    int temp, answer = 0;
    temp = n;
    while(temp > 0)
    {
        answer += temp % 10;
        temp /= 10;
    }

    return answer;
}