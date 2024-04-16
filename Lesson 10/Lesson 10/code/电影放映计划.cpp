#include <bits/stdc++.h>

using LL = long long;
using ld = long double;
using Pair = std::pair<int, int>;
#define inf 1'000'000'000

void solve(const int &Case) {
    int m, n;
    std::cin >> m >> n;
    std::vector<Pair> a(n);
    for (auto &[x, y]: a)std::cin >> x >> y;
    int K;
    std::cin >> K;
    std::vector<LL> f(m + 1);
    LL ans = 0;
    for (int T = 0; T <= m; T++) {
        if (T != 0)f[T] = std::max(f[T], f[T - 1]); // 可能中间不放电影，所以与 f[T - 1] 取 max
        for (const auto &[x, y]: a) {
            if (T + x + K <= m)f[T + x + K] = std::max(f[T + x + K], f[T] + y); // 状态转移
            if (T + x <= m)ans = std::max(ans, f[T] + y); // 计算答案，枚举当前电影放完之后未来不再放了
        }
        ans = std::max(ans, f[T]);
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