#include <bits/stdc++.h> // 与 C 一致

void solve(const int &Case) {
    std::priority_queue<int, std::vector<int>, std::greater<>> q1;
    int k, n;
    std::cin >> k >> n;
    for (int i = 0; i < k; i++) {
        int x;
        std::cin >> x;
        q1.push(x);
    }
    while (n--) {
        int x;
        std::cin >> x;
        if (q1.top() < x) {
            q1.pop();
            q1.push(x);
        }
        std::cout << q1.top() << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T = 1;
    for (int i = 1; i <= T; i++)solve(i);
    return 0;
}