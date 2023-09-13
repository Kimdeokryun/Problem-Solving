#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    vector<char> vec;
    int num = 0, count, count2;
    while (cin >> str) 
    {
        if (str.find("-") != -1) 
        {
            break;
        }
        num++;
        count = 0;
        count2 = 0;
        for (char c:str) 
        {
            if (c == '{') 
            { 
                vec.push_back(c);
                continue; 
            }
            else 
            {
                if (vec.empty()) 
                {
                    count++;
                    vec.push_back('{');
                }
                else { vec.pop_back(); }
            }
        }
        while (!vec.empty()) { vec.pop_back(); count2++; }

        cout << num << ". " << count +count2/2<< endl;
    }

    return 0;
}