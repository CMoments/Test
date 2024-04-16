#include <bits/stdc++.h>

using LL = long long;
using ld = long double;
using unl = __int128;
using Pair = std::pair<int, int>;
#define inf 1'000'000'000'000'000ll

void solve(const int &Case) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto &x: a)std::cin >> x;
    std::vector<std::vector<LL>> f(n, std::vector<LL>(n, inf));
    std::vector<LL> sum(n + 1);
    for (int i = 0; i < n; i++) {
        sum[i + 1] = sum[i] + a[i];
        f[i][i] = 0;
    }
    for (int len = 1; len <= n; len++) { // 区间 dp 一定是先枚举长度
        for (int l = 0, r = l + len; r < n; l++, r++) {
            for (int k = l; k < r; k++) {
                f[l][r] = std::min(f[l][r], f[l][k] + f[k + 1][r] + sum[r + 1] - sum[l]);
            }
        }
    }
    std::cout << f[0][n - 1] << '\n';
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