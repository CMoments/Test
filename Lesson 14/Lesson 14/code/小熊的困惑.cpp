// 记录乘积肯定不行，乘积会有非常多种
// 接下来的除法 / 都是下整除运算
// 但注意到 n / 1, n / 2, n / 3, ..., n / n 只有 2sqrt(n) 种不同的数
// 证明如下：n / i, 如果此时 i > sqrt(n), n / i <= sqrt(n), 那么此时 n / i 只有 sqrt(n) 种
// 若此时 i <= sqrt(n), i 只有 sqrt(n) 种, 那么此时 n / i 只有 sqrt(n) 种
// 所以总共只有 2sqrt(n) 种
// i * j <= m <=> i <= m / j
// (m / i) / j = m / (i * j)
// 所以此时我们不再记录乘积，而是记录 m / i, i 为当前所有数位的乘积

#include <bits/stdc++.h>

using LL = long long;
using ld = long double;
using unl = __int128;
using Pair = std::pair<int, int>;
#define inf 1'000'000'000'000'000ll

void solve(const int &Case) {
    LL n;
    int m;
    std::cin >> n >> m;
    // 这里为了方便，我直接使用 map 来记录 dp 状态
    std::map<Pair, LL> M;
    // 实际上, 记录 n / i 有种很好的方法, 是记录所有小于等于 sqrt 的数字，然后用两个下标映射数组
    // 感兴趣可以学习 min25 筛，在 min25 筛中用到
    std::function<LL(int, int, int, int,
                     const std::vector<int> &)> dp = [&](int dep, int up, int zero, int div,
                                                         const auto &a) {
        if (dep == -1)return (LL) ((zero ^ 1) && div != 0);
        if (up == 0 && zero == 0 && M.count({dep, div}))return M[{dep, div}];
        int lim = a[dep];
        if (!up)lim = 9;
        LL ret = 0;
        if (div > m) { // 如果数位中出现 0
            for (int i = 0; i <= lim; i++) {
                ret += dp(dep - 1, up && i == lim, zero && i == 0, div, a);
            }
        } else {
            for (int i = 0; i <= lim; i++) {
                if (i == 0) { // 有 0 时则特殊赋值 div
                    if (zero == 1)ret += dp(dep - 1, up && i == lim, 1, div, a);
                    else ret += dp(dep - 1, up && i == lim, 0, m + 1, a);
                    continue;
                }
                ret += dp(dep - 1, up && i == lim, 0, div / i, a);
            }
        }
        if (up == 0 && zero == 0)M[{dep, div}] = ret;
        return ret;
    };
    auto get = [&](LL x) {
        std::vector<int> a;
        while (x > 0)a.push_back((int) (x % 10)), x /= 10;
        int n = (int) a.size();
        return dp(n - 1, 1, 1, m, a);
    };
    std::cout << get(n) << '\n';
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