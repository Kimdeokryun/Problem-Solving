# include <iostream>
# include <string>
# include <stack>
# include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string sentence;
    getline(cin, sentence);

    stack<char> st;
    queue<char> q;
    bool open = false;


    for (char c : sentence)
    {
        if (c == '<')
        {
            while (!st.empty())
            {
                cout << st.top();
                st.pop();
            }
            q.push(c);
            open = 1;
            continue;
        }
        else if (c == '>') 
        {
            q.push(c);
            while (!q.empty())
            {
                cout << q.front();
                q.pop();
            }
            open = 0;
            continue;
        }
        if (open) 
        {
            q.push(c);
        }
        else 
        {
            if (c == ' ')
            {
                while (!st.empty())
                {
                    cout << st.top();
                    st.pop();
                }
                cout << ' ';
            }
            else if (isalnum(c))
            {
                st.push(c);
            }
        }
        
        
    }
    while (!st.empty())
    {
        cout << st.top();
        st.pop();
    }
    while (!q.empty())
    {
        cout << q.front();
        q.pop();
    }

    return 0;
}