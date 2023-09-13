#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    map<string, int> species;
    string line;
    int total_count = 0;

    while (getline(cin, line)) {
        // 입력이 없을 때까지 루프를 돕니다.
        if (line.empty()) {
            break;
        }

        species[line]++;
        total_count++;
    }

    for (auto element : species) 
    {
        printf("%s %.4f\n", element.first.c_str(), (double)element.second / total_count * 100);
    }

    return 0;
}