#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class candidate 
{
public:
	int rank1, rank2;

};

bool compare(candidate a, candidate b)
{
	return a.rank1 < b.rank1;
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int case_num;
	int N;
	int num;
	int ck;
	cin >> case_num;

	vector <candidate> a[20];

	//입력
	for (int n = 0; n < case_num; n++) {
		cin >> N;
		num = 0;
		for (int i = 0; i < N; i++)
		{
			candidate b;
			cin >> b.rank1 >> b.rank2;
			a[n].push_back(b);
		}
	}

	for (int n = 0; n < case_num; n++)
	{

		sort(a[n].begin(), a[n].end(), compare);
		ck = a[n][0].rank2;
		num = 1;
		for (int i = 1; i < a[n].size(); i++)
		{
			if (a[n][i].rank2 < ck) { ck = a[n][i].rank2; num++; }
			else { continue; }
		}
		cout << num << "\n";
	}


}

