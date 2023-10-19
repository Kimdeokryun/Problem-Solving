#include <string>
#include <vector>
#include <map>

#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    map<string, int> p_map;
    
    for(string name : completion)
    {
        p_map[name]++;
        
    }
    
    for(string name : participant)
    {
        if(p_map[name] == 0){answer = name; break;}
        p_map[name]--;
    }
    
    return answer;
}