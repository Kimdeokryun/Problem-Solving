#include <iostream>
#include <list>
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

    list <char> str_list(str.begin(), str.end());
    auto pointer = str_list.end();

    for (int i = 0; i < command_num; i++)
    {
        cin >> command;
        switch (command)
        {
        case 'P':
            cin >> ch;
            str_list.insert(pointer, ch);
            break;
        case 'L':
            if (pointer != str_list.begin()) { pointer--; }
            break;
        case 'D':
            if (pointer != str_list.end()) { pointer++; }
            break;
        case 'B':
            if (pointer != str_list.begin())
            {
                pointer--;
                pointer = str_list.erase(pointer);
            }
            break;
        }
    }

    for (char c : str_list)
    {
        cout << c;
    }

    return 0;
}