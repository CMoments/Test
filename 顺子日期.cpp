#include <bits/stdc++.h> // 与 C 中的代码一致

void solve(const int &Case) {
    const std::array<int, 12> Day = {31, 28, 31, 30, 31, 30,
                                     31, 31, 30, 31, 30, 31};
    int ans = 0;
    for (int month = 1; month <= 12; month++) {
        int a = month / 10, b = month % 10;
        for (int day = 1; day <= Day[month - 1]; day++) {
            int c = day / 10, d = day % 10;
            if (b + 1 == c) {
                if (a + 1 == b || c + 1 == d) {
                    ans++;
                }
            }
        }
    }
    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T = 1;
    for (int i = 1; i <= T; i++)solve(i);
    return 0;
}