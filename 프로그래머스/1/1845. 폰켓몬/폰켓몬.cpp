#include <iostream>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    
    int nums_size = nums.size();
    int answer_size = nums_size / 2;
    
    map<int,int> nums_map;
    
    for(int i =0; i< nums_size; i++)
    {
        nums_map[nums[i]] += 1;
    }
    
    int map_size = nums_map.size();
    
    if(answer_size <= map_size){answer = answer_size;}
    else if(answer_size > map_size){answer = map_size;}

    
    return answer;
}