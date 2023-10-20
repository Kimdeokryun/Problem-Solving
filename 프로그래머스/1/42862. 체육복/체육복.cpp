#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    int lost_size = lost.size();
    int reserve_size = reserve.size();
    
    vector<int> check(n, 1);
    for (int l : lost) {check[l-1]--;}
    for (int r : reserve) {check[r-1]++;}
    
    for (int i = 0; i < n; i++) 
    {
        if (!check[i]) 
        {
            if(0 < i && i < n-1)
            {
                if(check[i-1] == 2)
                {
                    check[i - 1]--;
                    check[i]++;
                }
                else if(check[i+1]==2)
                {
                    check[i + 1]--;
                    check[i]++;
                }
            }   
            else if (i == 0 && check[i + 1] == 2) // i = 맨 뒤가 아니고.
            {
                check[i + 1]--;
                check[i]++;
            }
            else if (i == n - 1 && check[i - 1] == 2) // i = 0이 아니고
            {
                check[i - 1]--;
                check[i]++;
            }
        }
    }
    
    for (int a : check)
    {
        if (a != 0)
        {
            answer++;
        }
    }
    
    return answer;
}