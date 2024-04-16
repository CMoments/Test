#include <bits/stdc++.h>

using LL = long long;
using ld = long double;
using Pair = std::pair<double, double>;
#define inf 1'000'000'000'000'000'000ll

void solve(const int &Case) {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> G(n, std::vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int x;
            std::cin >> x;
            G[i][j] = G[j][i] = x;
        }
    }
    std::vector<LL> f(1 << n);
    f[0] = 0;
    for (int S = 0; S < 1 << n; S++) {
        for (int i = 0; i < n; i++) {
            if (S >> i & 1)continue;
            for (int j = i + 1; j < n; j++) {
                if (S >> j & 1)continue;
                f[S | 1 << i | 1 << j] = std::max(f[S | 1 << i | 1 << j], f[S] + G[i][j]);
            }
        }
    }
    std::cout << *std::max_element(f.begin(), f.end()) << '\n';
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