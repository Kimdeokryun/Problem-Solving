#include<iostream>

using namespace std;

int main()
{
    long long n;
    cin >> n;

    long long result = 0;

    for (int i = 0; i < n; i++) 
    {
        result += (n+1) * i;
    }

    cout << result;
    return 0;
}