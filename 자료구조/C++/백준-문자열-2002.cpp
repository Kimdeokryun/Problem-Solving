#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    string str;
    vector<string> vec;
    int position = 0, count_result = 0;


    for (int i = 0; i < N; i++) 
    {
        cin >> str;
        vec.push_back(str);
    }


    for (int i = 0; i < N; i++)
    {
        cin >> str;
        if (str == vec[position]) 
        {
            position++;
            continue;
        }
        else
        {   
            auto it = find(vec.begin(), vec.end(), str);
            int index = distance(vec.begin(), it);
            vec.erase(vec.begin() + index);
            count_result++;
        }
    }

    cout << count_result << endl;

    return 0;
}