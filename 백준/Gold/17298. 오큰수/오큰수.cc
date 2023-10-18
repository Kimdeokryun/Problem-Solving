#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> numbers;
    int a;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        numbers.push_back(a);
    }

    vector<int> result(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++) 
    {
        while(!st.empty() && numbers[st.top()] < numbers[i])
        {
            result[st.top()] = numbers[i];
            st.pop();
        }
        st.push(i);
    }

    for (int i = 0; i < n; i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}