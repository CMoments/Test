// 比如我们要求 [1, 1234] 内的所有小明数
// 0134

#include <bits/stdc++.h>

using LL = long long;
using ld = long double;
using unl = __int128;
using Pair = std::pair<int, int>;
#define inf 1'000'000'000'000'000ll

std::vector<std::vector<std::vector<int>>> f(10, std::vector<std::vector<int>>(10, std::vector<int>(10, -1)));

void solve(const int &Case) {
    int L, R, K;
    std::cin >> K >> L >> R;
    std::function<int(int, int, int, int,
                      const std::vector<int> &)> dp = [&](int dep, int up, int zero, int pre,
                                                          const auto &a) {
        if (dep == -1)return zero ^ 1;
/*￥￥￥￥*/        if (up == 0 && zero == 0 && f[dep][pre][K] != -1)return f[dep][pre][K];
        // lim 当前这一位可以填的数的上界
        int lim = a[dep];
        if (!up)lim = 9;
        int ret = 0;
        // i 是枚举这一位填几
        for (int i = 0; i <= lim; i++) {
            // 前面已经填了数(不全是零)，那么就要考虑当前这一位是否合法
            if (zero == 0 && std::abs(i - pre) > K)continue;
            ret += dp(dep - 1, up && i == lim, zero && i == 0, i, a);
        }
/*￥￥￥￥*/             if (up == 0 && zero == 0)f[dep][pre][K] = ret;
        return ret;
    };
    auto get = [&](int x) {
        if (x == 0)return 0;
        std::vector<int> a;
        while (x > 0)a.push_back(x % 10), x /= 10;
        int n = (int) a.size();
        return dp(n - 1, 1, 1, 0, a);
    };
    std::cout << get(R) - get(L - 1) << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T = 1;
    std::cin >> T;
    for (int Case = 1; Case <= T; Case++)solve(Case);
    return 0;
}
