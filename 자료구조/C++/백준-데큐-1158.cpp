# include <iostream>
# include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;
    
    queue<int> numbers;

    for (int i = 1; i <= N; ++i) {
        numbers.push(i);
    }

    int cursor = K - 1;

    cout << "<";

    //문제 해결
    while (numbers.size() > 1) {
        for (int i = 1; i < K; i++) {
            int tmp = numbers.front();
            numbers.pop(); //앞에서 빼서
            numbers.push(tmp); //뒤에 다시 넣는다
        }
        cout << numbers.front() << ", ";
        numbers.pop();
    }

    cout << numbers.front() << ">\n";


    return 0;
}