#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    unordered_map<string, int> phonenumbers;
    
    for(string number : phone_book)
    {
        phonenumbers[number] = 1;
    }
    
    for(string number : phone_book)
    {
        int num_size = number.size();
        string str_num = "";
        for(char num : number)
        {
            str_num += num;
            if(phonenumbers[str_num] && str_num != number){answer = false; return answer;}
        }
        
    }
    
    
    
    return answer;
}