#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> wears;
    vector<int> wear_nums;
    
    //옷 종류별로 확인
    for(vector<string> wear: clothes)
    {
        wears[wear[1]]++;
    }
    
    //모든 조합 계산
    for(auto it = wears.begin(); it != wears.end(); it++)
    {
        answer *= it->second + 1;       // 옷을 안 입는 경우
    }
    
    return answer-1; // 하나도 안 입는 경우를 뺀다.
}