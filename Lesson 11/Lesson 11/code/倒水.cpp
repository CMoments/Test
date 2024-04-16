#include <bits/stdc++.h>

using LL = long long;
using ld = long double;
using Pair = std::pair<int, int>;
#define inf 1'000'000'000'000'000'000ll

void solve(const int &Case) {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n), b(n), c(n), d(n), e(n);
    for (int i = 0; i < n; i++)std::cin >> a[i] >> b[i] >> c[i] >> d[i] >> e[i];
    std::vector<LL> f(m + 1, -inf);
    f[0] = 0;
    for (int i = 0; i < n; i++) {
        auto g = f;
        std::vector<LL>(m + 1, -inf).swap(f);
        for (int j = 0; j <= m; j++) {
            f[j] = g[j] + e[i];
            if (j >= a[i])f[j] = std::max(f[j], g[j - a[i]] + b[i]);
            if (j >= c[i])f[j] = std::max(f[j], g[j - c[i]] + d[i]);
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