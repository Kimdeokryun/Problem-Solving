#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> h(N + 2);

    stack<int> s;
    s.push(0);

    int result = 0;

    for (int i = 1; i <= N; i++)
    {
        cin >> h[i];
    }

    for (int i = 1; i <= N + 1; i++)
    {
        while (!s.empty() && h[s.top()] > h[i])
        {
            int check = s.top();
            s.pop();
            result = max(result, h[check] * (i - s.top() - 1));
        }
        s.push(i);
    }

    cout << result << endl;
    return 0;
}
