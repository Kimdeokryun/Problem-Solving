# include <iostream>
# include <string>
# include <list>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    int command_num;
    char command, ch;

    cin >> str;
    cin >> command_num;

    list <char> li(str.begin(), str.end());
    auto pointer = li.end();

    for (int i = 0; i < command_num; i++) 
    {
        cin >> command;
        if (command == 'P')
        {
            cin >> ch;
            li.insert(pointer, ch);
        }
        else if (command == 'L') 
        {
            if (pointer != li.begin()) { pointer--; }          
        }
        else if (command == 'D') 
        {
            if (pointer != li.end()) { pointer++; }
        }
        else if (command == 'B') 
        {
            if (pointer != li.begin()) 
            { 
                pointer--; 
                pointer = li.erase(pointer); 
            }
        }
    }

    for (pointer = li.begin(); pointer != li.end(); pointer++)
        cout << *pointer;

    return 0;
}