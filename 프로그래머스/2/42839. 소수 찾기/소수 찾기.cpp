#include <string>
#include <vector>
#include <cmath>
#include <unordered_set>

using namespace std;

unordered_set<int> primeset;

bool isPrime(int n)
{
    if(n == 0 || n == 1){return false;}
    
    int num = sqrt(n);
    
    for(int i = 2; i <= num; i++)
    {
        if(n%i == 0){return false;}
    }
    return true;
    
}

void makeCombination(string comb, string others)
{
    // 1. 현 조합을 numberSet에 추가한다.
    if (comb != "")
    {
        int number = stoi(comb);
        if(isPrime(number))
            {
                primeset.insert(number);
            }
    }
        
    // 2. 현 조합 + others[i]를 조합하여 새로운 조합을 만든다.
    for (int i = 0; i < others.size(); i++)
        makeCombination(comb + others[i], others.substr(0, i) + others.substr(i + 1));
}

int solution(string numbers) {
    int answer = 0;
    
    makeCombination("", numbers);
    
    answer = primeset.size();
    return answer;
}