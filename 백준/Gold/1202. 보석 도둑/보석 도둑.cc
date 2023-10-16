#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

class jewel 
{
public:
	int weight;
	int price;
};


bool compare(jewel a, jewel b) 
{
	if (a.weight == b.weight) { return a.price > b.price; }
	return a.weight < b.weight;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	cin >> N >> K;
	vector<jewel> A;
	vector<int> bag;
	for (int i = 0; i < N; i++) 
	{
		jewel j;
		cin >> j.weight >> j.price;
		A.push_back(j);
	}
	for (int i = 0; i < K; i++)
	{
		int a; cin >> a;
		bag.push_back(a);
	}
	sort(A.begin(), A.end(), compare);
	sort(bag.begin(), bag.end());

	priority_queue<int> pq;
	long long sum = 0;
	int idx = 0;
	for (int i = 0; i < K; i++)
	{
		while (idx < N && bag[i] >= A[idx].weight) {
			pq.push(A[idx].price); 
			idx++;
		}

		if (!pq.empty()) 
		{
			sum += pq.top();
			pq.pop();
		}
		
	}

	cout << sum << "\n";
}

