# include <iostream>
# include <stack>
# include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    cin.ignore(); // 입력 버퍼 비우기
    string sentence;

    stack<char> st;

    for (int i = 0; i < N; i++)
    {
        getline(cin, sentence);
        
        for (char c : sentence) 
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
        while (!st.empty())
        {
            cout << st.top();
            st.pop();
        }
        cout << endl;
    }

    return 0;
}