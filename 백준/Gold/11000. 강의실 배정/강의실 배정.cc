#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<deque>
using namespace std;


bool compare(pair<int, int> p1, pair<int ,int> p2)
{
	return p1.first == p2.first ? p1.second < p2.second : p1.first < p2.first;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	int s, e, result = 0, cnt = 0;
	vector<pair<int, int>> meeting;
	vector<pair<int, int>> q1;
	for (int i = 0; i < n; i++) { cin >> s >> e; meeting.push_back(make_pair(s, 1)); meeting.push_back(make_pair(e, -1));}

	sort(meeting.begin(), meeting.end(), compare);

	for (int i = 0; i < meeting.size(); i++)
	{
		cnt += meeting[i].second;
		result = max(result, cnt);
	}
	cout << result << endl;
}