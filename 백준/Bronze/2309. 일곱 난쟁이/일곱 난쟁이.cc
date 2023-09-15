#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() 
{
	int sum, num;
	int temp1=0, temp2=0;
	vector<int> data;

	sum = 0;
	for (int i = 0; i < 9; i++) 
	{
		cin >> num;
		sum += num;
		data.push_back(num);
	}

	sort(data.begin(), data.end());
	sum = sum - 100;
	
	for (int i = 0; i < 9; i++) 
	{
		num = data[i];
		for (int j = i+1; j < 9; j++) 
		{
			if ((num + data[j]) == sum) { temp1 = i; temp2 = j; break; }
		}
	}

	data.erase(data.begin() + temp1);
	data.erase(data.begin() + (temp2-1));

	for (int i = 0; i < 7; i++) { cout << data[i] << endl; }

}