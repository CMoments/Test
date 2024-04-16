#include <bits/stdc++.h> // 与 C 一致

void solve(const int &Case) {
    int n;
    std::cin >> n;
    std::map<int, int> M;
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        M[x]++;
    }
    int ans = 0;
    for (const auto &[x, y]: M) {
        if (y < x) {
            ans += y;
        }
        else {
            ans += y - x;
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