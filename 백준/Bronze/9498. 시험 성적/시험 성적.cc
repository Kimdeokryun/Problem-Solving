#include<iostream>

using namespace std;

int main() 
{
	int score;
	cin >> score;

	char score_alpha;
	if (score >= 90) { score_alpha = 'A'; }
	else if (score >= 80) { score_alpha = 'B'; }
	else if (score >= 70) { score_alpha = 'C'; }
	else if (score >= 60) { score_alpha = 'D'; }
	else { score_alpha = 'F'; }

	cout << score_alpha;
	return 0;
}