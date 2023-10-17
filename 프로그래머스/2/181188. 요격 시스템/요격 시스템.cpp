#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(vector<int> a, vector<int> b)
{
    if(a[1] == b[1]){return a[0] < b[0];}
    return a[1] < b[1];
}

int solution(vector<vector<int>> targets) {
    int answer = 0;
    
    int missile_size = targets.size();
    
    sort(targets.begin(), targets.end(), compare);
    
    int check = -1;
    
    for(int i =0; i< missile_size; i++)
    {
        if(check <= targets[i][0])
        {
            check = targets[i][1];
            answer++;
        } 
    }
    
    
    return answer;
}