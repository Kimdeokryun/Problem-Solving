# include <iostream>
# include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, num;
    cin >> N;
    for (int i = 0; i < N * N; i++) 
    {
        cin >> num;
        pq.push(num);
        if (pq.size() > N) { pq.pop(); }
    }
    
    cout << pq.top() << endl;
   
    return 0;
}