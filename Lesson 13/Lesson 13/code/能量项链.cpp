#include <bits/stdc++.h>

using LL = long long;
using ld = long double;
using Pair = std::pair<int, int>;
#define inf 1'000'000'000

void solve(const int &Case) {
    int n;
    std::cin >> n;
    std::vector<int> a(n + n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        a[i + n] = a[i];
    }
    a.push_back(a[0]); // 为了方便起见，令 a[2 * n] = a[0]
    std::vector<std::vector<LL>> f(n + n, std::vector<LL>(n + n));
    for (int len = 1; len < n; len++) {
        for (int l = 0, r = len; r < n + n; l++, r++) {
            for (int k = l; k < r; k++) {
                f[l][r] = std::max(f[l][r], f[l][k] + f[k + 1][r] + a[l] * a[k + 1] * a[r + 1]);
            }
        }
    }
    LL ans = 0;
    for (int i = 0; i < n; i++) {
        ans = std::max(ans, f[i][i + n - 1]);
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