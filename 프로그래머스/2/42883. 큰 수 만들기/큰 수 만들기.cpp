#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
	string answer = "";
    int idx = -1;
    for(int i=0; i<number.size()-k; i++){       // 숫자 자리수만 채워주기
        char maxV = ' ';
        for(int j=idx+1; j<=k+i; j++){      // cursor 역할을 하는 j.  cursor 는 number의 끝까지만 갈 수 있다.
            if(maxV < number[j]){
                maxV = number[j];
                idx = j;
            }
        }
        answer += maxV;
    }
	return answer;
}