#include <bits/stdc++.h>

using LL = long long;
using ld = long double;
using Pair = std::pair<LL, int>;
#define inf 1'000'000'000'000'000'000ll

void solve(const int &Case) {
    int n, m;
    std::cin >> n >> m;
    if (m > n)std::swap(n, m);
    std::vector<int> ban(1 << m);
    for (int S = 0; S < 1 << m; S++) {
        for (int i = 0; i < m - 1; i++) {
            if ((S >> i & 1) && (S >> (i + 1) & 1)) {
                ban[S] = 1;
                break;
            }
        }
    }
    std::vector<LL> f(1 << m);
    f[0] = 1;
    for (int i = 0; i < n; i++) {
        auto g = f;
        std::vector<LL>(1 << m).swap(f);
        for (int j = 0; j < m; j++) {
            for (int S = 0; S < 1 << m; S++) {
                if (S >> j & 1) {
                    g[S] += g[S ^ (1 << j)];
                }
            }
        }
        for (int T = 0; T < 1 << m; T++) {
            if (ban[T])continue;
            int S = T ^ ((1 << m) - 1);
            f[T] = g[S];
        }
    }
    std::cout << std::accumulate(f.begin(), f.end(), 0ll) << '\n';
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