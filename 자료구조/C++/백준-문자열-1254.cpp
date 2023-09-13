#include <iostream>

using namespace std;

bool isPalindrome(const string& str, int start, int end) 
{
    while (start < end) 
    {
        if (str[start] != str[end]) 
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;

    int len = str.size();
    int answer = len;

    for (int i = 0; i < len; i++) 
    {
        if (isPalindrome(str, i, len-1))
        {
            answer = len + i;
            break;
        }
    }

    cout << answer << endl;

    return 0;
}