#include <bits/stdc++.h>

using LL = long long;
using ld = long double;
using Pair = std::pair<int, int>;
#define inf 1'000'000'000

void solve(const int &Case) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto &i: a)std::cin >> i;
    std::vector<std::vector<int>> f(n, std::vector<int>(n, -inf)), g(n, std::vector<int>(n, -inf));
    // f: left, g: right
    for (int i = 0; i < n; i++) {
        f[i][i] = g[i][i] = a[i];
    }
    for (int len = 1; len < n; len++) {
        for (int l = 0, r = l + len; r < n; l++, r++) {
            f[l][r] = std::max(g[l + 1][r] - 10 * (r - l) + a[l], f[l + 1][r] - 10 + a[l] / 2);
            g[l][r] = std::max(f[l][r - 1] - 10 * (r - l) + a[r], g[l][r - 1] - 10 + a[r] / 2);
        }
    }
    std::cout << std::max(f[0][n - 1], g[0][n - 1]) << '\n';
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