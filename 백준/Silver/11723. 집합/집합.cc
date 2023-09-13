#include <iostream>
using namespace std;

// 비트마스크
/*
And 연산 (&): 대응하는 두 비트가 모두 1이면 1 반환
OR 연산 ( | ): 대응하는 두 비트 중 하나라도 1이면 1 반환
Shift 연산 («,») : 비트를 왼쪽 또는 오른쪽으로 한칸씩 이동
XOR 연산 (^): 대응하는 두 비트가 다르면 1 같으면 0 반환
Not 연산 (~) : 비트를 반전


add -> |= (1 << val)
remove -> &= ~(1 << val)
check -> &= (1 << val)
toggle -> ^= (1 << val)
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int M;
	cin >> M;

	string command;
	int num, bit = 0;

	for (int i = 0; i < M; i++) 
	{
		cin >> command;
		if (command == "add")
		{
			cin >> num;
			// or 연산자를 통해 val번째 자리수를 1로 채운다.
			bit |= (1 << num);
		}
		else if (command == "remove")
		{
			cin >> num;
			// ex) 1000 & ~(1000) = 0000
			bit &= ~(1 << num);
		}
		else if (command == "check")
		{
			cin >> num;
			if (bit & (1 << num)) { cout << "1\n"; }
			else { cout << "0\n"; }
		}
		else if (command == "toggle")
		{
			cin >> num;
			// BIT의 val번째 자리가 1이라면 1^1=0이 되어 1->0이 되고
			// val번째 자리가 0이라면 0^1=1 이 되어 0 -> 1이 된다.
			bit ^= (1 << num);
		}
		else if (command == "all") { bit = (1 << 21) - 1; }
		else if (command == "empty") { bit = 0; }
	}
	return 0;
}