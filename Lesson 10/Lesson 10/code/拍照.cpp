#include <bits/stdc++.h>

using LL = long long;
using ld = long double;
using Pair = std::pair<ld, ld>;
#define inf 1'000'000'000

void solve(const int &Case) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto &i: a)std::cin >> i;
    std::vector<int> f(n), g(n);
    // f: lis, g: lds
    for (int i = 0; i < n; i++) {
        f[i] = 1;
        for (int j = 0; j < i; j++)if (a[j] <= a[i])f[i] = std::max(f[i], f[j] + 1);
    }
    for (int i = n - 1; i >= 0; i--) {
        g[i] = 1;
        for (int j = n - 1; j > i; j--)if (a[j] <= a[i])g[i] = std::max(g[i], g[j] + 1);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)ans = std::max(ans, f[i] + g[i] - 1);
    std::cout << n - ans << '\n';
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