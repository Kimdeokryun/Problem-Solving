#include <iostream>
#include <vector>
#include <string>

using namespace std;

string str;
string target;

vector<int> getPi() {
    int len = target.size();
    int j = 0;
    vector<int> pi(len, 0);

    for (int i = 1; i < len; i++) {
        // j번째가 일치하지 않을 경우 
        // j-1번째일때 pi[j-1]개가 일치함 -> pi[j-1]-1까지 일치
        // j-1번째일때 pi[j-1]째 글자가 i와 일치해야 j-1번째부터 다시 시작할 수 있음
        while (target[i] != target[j] && j > 0)
            j = pi[j - 1];

        if (target[i] == target[j]) {
            j++;
            pi[i] = j;
        }
    }

    return pi;
}

vector<int> solve() {

    vector<int> ans;
    vector<int> pi = getPi();
    int j = 0;

    for (int i = 0; i < str.size(); i++) {
        while (str[i] != target[j] && j > 0)
            j = pi[j - 1];

        if (str[i] == target[j]) {
            if (j == target.length() - 1) {
                ans.push_back(i - j);
                j = pi[j];
            }
            else {
                j++;
            }
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // ifstream cin;
    // cin.open("input.txt");

    getline(cin, str);
    getline(cin, target);

    vector<int> ans = solve();

    cout << ans.size() << endl;
    for (int a : ans)
        cout << a + 1 << " ";
}


// 내가 짠 코드
/*
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string sentence, str;
    getline(cin, sentence);
    cin.ignore();
    cin >> str;

    vector<int> A_hashmap;
    vector<int> idxlist;
    int idx;

    for (int i = 0; i < sentence.size(); i++)
    {
        if (sentence[i] == str[0])
        {
            if (i + str.size() >= sentence.size()) { break; }
            A_hashmap.push_back(i);
        }
    }

    for (int i = 0; i < A_hashmap.size(); i++)
    {
        idx = A_hashmap[i];
        idxlist.push_back(idx);
        for (int j = 1; j < str.size(); j++)
        {
            if (str[j] == sentence[idx + j]) { continue; }
            else { idxlist.pop_back(); break; }
        }
    }

    cout << idxlist.size() << endl;
    for (int idx : idxlist)
    {
        cout << idx << " ";
    }


    return 0;
}
* 
* 
* 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string sentence, str;
    getline(cin, sentence);
    cin.ignore();
    cin >> str;

    vector<int> hashmap[100];
    vector<int> idxlist;
    bool check;
    int idx = 0, before_idx = -1;

    
    for (int i = 0; i < sentence.size(); i++) 
    {
        if (sentence[i] == ' ') { continue; }
        hashmap[int(sentence[i]) - 65].push_back(i);
    }

    for (int i = 0; i < hashmap[int(str[0]) - 65].size(); i++) 
    {
        idx = hashmap[int(str[0]) - 65][i];
        if (idx + str.size() > sentence.size()) { break; }
        idxlist.push_back(idx);
        for (int j = 1; j < str.size(); j++)
        {
            check = false;
            for (int element : hashmap[int(str[j]) - 65])
            {
                if (idx + j == element)
                {
                    check = true;
                    break;
                }
            }
            if (!check)
            {
                idxlist.pop_back();
                break;
            }
        }
    }

    cout << idxlist.size() << endl;
    for (int idx : idxlist) 
    {
        cout << idx << " ";
    }


    return 0;
}
*/