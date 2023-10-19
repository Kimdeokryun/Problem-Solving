#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    int answers_size = answers.size();
    int first_a[5] = {1, 2, 3, 4, 5};
    int second_a[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    int third_a[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    int first = 0, second = 0, third = 0;

    for(int i =0; i< answers_size; i++)
    {
        if(answers[i] == first_a[i%5]){first++;}
        if(answers[i] == second_a[i%8]){second++;}
        if(answers[i] == third_a[i%10]){third++;}
    }
    
    int max_solve = max(first, max(second, third));
    if(first == max_solve)
    {
        answer.push_back(1);
    }
    if(second == max_solve)
    {
        answer.push_back(2);
    }
    if(third == max_solve)
    {
        answer.push_back(3);
    }
    
    return answer;
}