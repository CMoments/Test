#include <bits/stdc++.h>

using LL = long long;
using ld = long double;
using unl = __int128;
using Pair = std::pair<int, int>;
#define inf 1'000'000'000'000'000ll

std::vector<std::vector<LL>> f(19, std::vector<LL>(4, -1));

void solve(const int &Case) {
    LL L, R;
    std::cin >> L >> R;
    std::function<LL(int, int, int, int,
                     const std::vector<int> &)> dp = [&](int dep, int up, int zero, int sum,
                                                         const auto &a) {
        if (dep == -1)return 1ll;
        if (up == 0 && zero == 0 && f[dep][sum] != -1)return f[dep][sum];
        int lim = a[dep];
        if (!up)lim = 9;
        LL ret = 0;
        for (int i = 0; i <= lim; i++) {
            if (i == 0) {
                ret += dp(dep - 1, up && i == lim, zero, sum, a);
                continue;
            }
            if (sum == 0)continue;
            ret += dp(dep - 1, up && i == lim, 0, sum - 1, a);
        }
        if (up == 0 && zero == 0)f[dep][sum] = ret;
        return ret;
    };
    auto get = [&](LL x) {
        std::vector<int> a;
        while (x > 0)a.push_back((int) (x % 10)), x /= 10;
        int n = (int) a.size();
        return dp(n - 1, 1, 1, 3, a);
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