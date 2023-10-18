#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    string str_number;
    cin >> str_number;

    vector <char> numbers;
    int temp_k = k;
    for (int i = 0; i < n; i++) {

        while (temp_k && !numbers.empty() && numbers.back() < str_number[i]) {
            numbers.pop_back();
            temp_k--;
        }
        numbers.push_back(str_number[i]);
    }

    for (int i = 0; i < n-k; i++)
    {
        cout << numbers[i];
    }

    return 0;
}