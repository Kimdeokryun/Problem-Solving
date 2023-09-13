#include <iostream>
#include <string>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    string s;

    cin >> N >> M;
    cin >> s;
    
    int k, answer = 0;

    for (int i = 0; i < M; i++) 
    {
        k = 0;
        if (s[i] == 'O') { continue; }
        else 
        {
            while (s[i + 1] == 'O' && s[i + 2] == 'I')
            {
                k++;
                if (k == N) 
                {
                    k--;
                    answer++;
                }
                i += 2;
            }
        }
    }
    
    cout << answer << endl;
    return 0;
}