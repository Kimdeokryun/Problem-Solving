#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    int h = 0, w = 0;
    
    int sizes_len = sizes.size();
    for(int i =0; i<sizes_len; i++)
    {
        int idx_0 = sizes[i][0];
        int idx_1 = sizes[i][1];
        if(idx_0 > idx_1)
        {
            h = max(h, idx_0);
            w = max(w, idx_1);
        }
        else
        {
            h = max(h, idx_1);
            w = max(w, idx_0);
        }
        
    }
    
    answer = h * w;
    return answer;
}