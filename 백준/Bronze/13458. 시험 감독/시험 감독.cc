#include <iostream>
#include <vector>

using namespace std;

int main() 
{
	long long n, a;
	long long b, c;
	cin >> n; 
	
	vector<long long> N_room(n);

	for (long long i = 0; i < n; i++)
	{
		cin >> N_room[i];
	}
	
	cin >> b >> c;

	long long min_result = 0;

	for (long long number_of_tester : N_room)
	{
		min_result += 1;
		number_of_tester -= b;
		if (number_of_tester > 0) { 
			min_result += number_of_tester / c;
			if (number_of_tester % c != 0) { min_result += 1; }
		}
	}

	cout << min_result << '\n';
}