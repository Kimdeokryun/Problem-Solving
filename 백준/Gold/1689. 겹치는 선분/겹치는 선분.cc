#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

int N;
std::vector <std::pair <int, int>> Get;

void Input() {
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        int X, Y;
        std::cin >> X >> Y;
        Get.push_back({ X, Y });
    }
    std::sort(Get.begin(), Get.end());
}

void Solve() {
    std::priority_queue<int, std::vector <int>, std::greater<int>> Q;
    Q.push(Get[0].second);
    int Ans = 1;
    for (int i = 1; i < N; i++) {
        while (!Q.empty() && Q.top() <= Get[i].first) Q.pop();
        Q.push(Get[i].second);
        Ans = std::max(Ans, (int)Q.size());
    }
    std::cout << Ans;
}

int main() {
    Input();
    Solve();
}