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

    //���� �ذ�
    while (numbers.size() > 1) {
        for (int i = 1; i < K; i++) {
            int tmp = numbers.front();
            numbers.pop(); //�տ��� ����
            numbers.push(tmp); //�ڿ� �ٽ� �ִ´�
        }
        cout << numbers.front() << ", ";
        numbers.pop();
    }

    cout << numbers.front() << ">\n";


    return 0;
}