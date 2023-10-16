#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() 
{
	int n, m;
	cin >> n >> m;
	
	vector<int> book_pos(n);
	int negative = 0;
	
	for (int i = 0; i < n; i++) 
	{
		cin >> book_pos[i];
		if (book_pos[i] < 0) { negative++; }
	}

	sort(book_pos.begin(), book_pos.end());

	int result = 0;

	// 양수값 세기
	for (int i = n - 1; i >= negative; i -= m) 
	{
		result += abs(book_pos[i] * 2);
	}
	for (int i = 0; i < negative; i += m)
	{
		result += abs(book_pos[i] * 2);
	}

	result -= max(abs(book_pos[0]), abs(book_pos[n - 1]));	// 양쪽 끝에 있는 값들 중에서 더 큰 값은 마지막에 방문해서 왕복 X 

	cout << result << "\n";
	return 0;
}