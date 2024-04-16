#include <bits/stdc++.h>

using LL = long long;
using ld = long double;
using unl = __int128;
using Pair = std::pair<int, int>;
#define inf 1'000'000'000'000'000'000ll

void solve(const int &Case) {
    int n;
    std::cin >> n;
    std::vector<Pair> a(n);
    for (auto &[x, y]: a)std::cin >> x >> y, x++; // 因为合法的购物情况等价于 \sum (t_{i_j} + 1) >= n
    std::vector<LL> f(n, inf);
    f[0] = 0;
    LL ans = inf;
    for (const auto &[x, y]: a) {
        auto g = f;
        std::vector<LL>(n, inf).swap(f);
        for (int i = 0; i < n; i++) {
            f[i] = std::min(f[i], g[i]);
            // 由于我们要求的合法限制是 x 的和 >= n
            // 所以意味着如果 x 的和 >= n 了，就可以直接和 ans 取 min
            // 具体来说，如果 i + x >= n，那么此时的 i + x 已经是个合法的答案状态
            // 所以直接拿 f[i] + y 和 ans 取 min
            // 否则就是正常的背包
            if (i + x >= n)ans = std::min(ans, g[i] + y);
            else f[i + x] = std::min(f[i + x], g[i] + y);
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