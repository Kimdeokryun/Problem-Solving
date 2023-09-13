# include <iostream>
# include <string>
# include <queue>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    string command;
    int number;
    queue<int> list;

    for (int i = 0; i < N; i++) 
    {
        cin >> command;
        if (command == "push") 
        {
            cin >> number;
            list.push(number);
        }
        else if (command == "front") 
        {
            if (!list.empty()) { cout << list.front() << endl; }
            else { cout << -1 << endl; }
        }
        else if (command == "back") 
        {
            if (!list.empty()) { cout << list.back() << endl; }
            else { cout << -1 << endl; }
        }
        else if (command == "size") 
        {
            cout << list.size() << endl;
        }
        else if (command == "empty") 
        {
            if (!list.empty()) { cout << 0 << endl; }
            else { cout << 1 << endl; }
        }
        else if (command == "pop") 
        {
            if (!list.empty()) { cout << list.front() << endl; list.pop(); }
            else { cout << -1 << endl; }
        }
    }
    
    return 0;
}