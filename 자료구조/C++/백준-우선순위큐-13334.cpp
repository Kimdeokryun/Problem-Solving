# include <iostream>
# include <queue>
# include <vector>
# include <algorithm>
using namespace std;

vector<pair<int, int>> people;
priority_queue<int, vector<int>, greater<int>> pq;

bool cmp(pair<int, int> a, pair<int, int> b) 
{
    if (a.second == b.second) 
    {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, h, o, d;
    int start, end, max_result = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> h >> o;
        if (o < h)
        {
            people.push_back(make_pair(o, h));
        }
        else
        {
            people.push_back(make_pair(h, o));
        }
    }
    cin >> d;

    sort(people.begin(), people.end(), cmp);

    for (int i = 0; i < n; i++)
    {
        start = people[i].first;
        end = people[i].second;

        if (end - start <= d) 
        {
            pq.push(start);
            while (!pq.empty()) 
            {
                if (pq.top() + d >= end) 
                {
                    break;
                }
                pq.pop();
            }
            max_result = max(max_result, (int)pq.size());
        }
    }

    cout << max_result << endl;

    return 0;
}


// ³»°¡ Ç¬ Ç®ÀÌ
/*
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
vector<pair<int, int>> result;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, h, o, d, max_num, max_result = 0;
    cin >> n;
    
    for (int i = 0; i < n; i++) 
    {
        cin >> h >> o;
        if (o < h) 
        {
            pq.push(make_pair(o, h));
        }
        else 
        {
            pq.push(make_pair(h, o));
        }
    }
    cin >> d;

    for (int i = 0; i < n; i++)
    {
        //cout << "top:" << pq.top().first << " " << pq.top().second << endl;
        if (pq.top().second - pq.top().first <= d) 
        {
            if (result.empty())
            {
                result.push_back(make_pair(pq.top().first, 1));
            }
            else
            {
                for (int j = 0; j < result.size(); j++)
                {
                    max_num = result[j].first;
                    if (result[j].first <= pq.top().first && pq.top().second <= result[j].first + d)
                    {
                        result[j].second++;
                        max_result = max(max_result, result[j].second);
                        continue;
                    }
                }

                if (pq.top().first > max_num)
                {
                    result.push_back(make_pair(pq.top().first, 1));
                }
            }
        }
        pq.pop();
    }

    cout << max_result << endl;

    return 0;
}
*/