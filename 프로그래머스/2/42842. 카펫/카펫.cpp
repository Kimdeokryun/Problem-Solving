#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int answer_x;
    int answer_y;
    
    int max_x = brown/2;
    
    for(int x = 3; x <= max_x; x++)
    {
        for(int y = 3; y <= x; y++)
        {
            if((x-2)*(y-2) == yellow && 2 * x + 2 * (y-2) == brown)
            {
                answer_x = x;
                answer_y = y;
            }
        }
        
    }
    answer.push_back(answer_x);
    answer.push_back(answer_y);
    return answer;
}