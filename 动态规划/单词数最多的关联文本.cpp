#include <bits/stdc++.h>

using LL = long long;
using ld = long double;
using Pair = std::pair<LL, int>;
#define inf 1'000'000'000'000'000'000ll

void solve(const int &Case) {
    int n;
    std::cin >> n;
    std::vector<std::string> a(n);
    for (auto &i: a)std::cin >> i;
    std::vector<std::vector<int>> f(1 << n, std::vector<int>(n));
    for (int i = 0; i < n; i++)f[1 << i][i] = 1;
    int ans = 0;
    for (int S = 0; S < (1 << n); S++) {
        for (int i = 0; i < n; i++) {
            if (S >> i & 1) { // S 第 i 位必须是 1
                int T = S ^ (1 << i);
                for (int j = 0; j < n; j++) {
                    if (f[T][j] && a[j].back() == a[i][0]) {
                        f[S][i] = 1;
                    }
                }
            }
            if (f[S][i])ans = std::max(ans, __builtin_popcount(S));
        }
    }
    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T = 1;
//    std::cin >> T;
    for (int Case = 1; Case <= T; Case++)solve(Case);
    return 0;
}