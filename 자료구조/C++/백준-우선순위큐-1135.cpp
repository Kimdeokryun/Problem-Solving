# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

int n;
vector<int> tree[51];

int solve(int node) 
{
    if (tree[node].empty()) 
    {
        return 1;
    }
    
    vector<int> ch;

    for (int i = 0; i < tree[node].size(); i++) 
    {
        ch.push_back(solve(tree[node][i]) + 1);
    }

    sort(ch.begin(), ch.end(), greater<int>());

    int ret = 0;
    for (int i = 0; i < ch.size(); i++) { ret = max(ret, ch[i] + i); }

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, num;
    cin >> N;
    
    for (int i = 0; i < N; i++) 
    {
        cin >> num;
        if (i != 0) { tree[num].push_back(i); }
    }

    cout << solve(0) - 1 << endl;

    return 0;
}