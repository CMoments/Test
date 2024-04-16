#include <bits/stdc++.h>

using LL = long long;
using ld = long double;
using Pair = std::pair<int, int>;
#define inf 1'000'000'000

void solve(const int &Case) {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        int S = 0;
        for (int j = 0; j < m; j++) {
            int x;
            std::cin >> x;
            S = S * 2 | x;
        }
        a[i] = S;
    }
    std::vector<int> ban(1 << m);
    for (int S = 0; S < 1 << m; S++) {
        for (int i = 0; i < m - 1; i++) {
            if ((S >> i & 1) && (S >> (i + 1) & 1)) {
                ban[S] = 1;
                break;
            }
        }
    }
    std::vector<int> f(1 << m, -1);
    f[0] = 0;
    for (int i = 0; i < n; i++) {
        auto g = f;
        std::vector<int>(1 << m, -1).swap(f);
        for (int j = 0; j < m; j++) {
            for (int S = 0; S < 1 << m; S++) {
                if (S >> j & 1) {
                    g[S] = std::max(g[S], g[S ^ (1 << j)]);
                }
            }
        }
        for (int T = 0; T < 1 << m; T++) {
            if (T & a[i] || ban[T])continue;
            int S = T ^ ((1 << m) - 1), v = __builtin_popcount(T);
            f[T] = g[S] + v;
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