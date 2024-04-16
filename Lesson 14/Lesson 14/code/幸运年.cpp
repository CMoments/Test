#include <bits/stdc++.h>

using LL = long long;
using ld = long double;
using unl = __int128;
using Pair = std::pair<int, int>;
#define inf 1'000'000'000'000'000ll

std::vector<std::vector<LL>> f(13, std::vector<LL>(6, -1));

void solve(const int &Case) {
    LL l, r;
    std::cin >> l >> r;
    // 0: invalid
    // 1: 2
    // 2: 20
    // 3: 202
    // 4: 1
    // 5: valid
    auto tran = [&](const int &tag, const int &x) {
        if (tag == 5)return 5;
        if (tag == 3 && x == 3)return 5;
        if (tag == 4 && x == 4)return 5;
        if (tag == 3 && x == 0)return 2;
        if (tag == 1 && x == 0)return 2;
        if (tag == 2 && x == 2)return 3;
        if (x == 1)return 4;
        if (x == 2)return 1;
        return 0;
    };
    std::function<LL(int, int, int, int,
                     const std::vector<int> &)> dp = [&](int dep, int up, int zero, int tag,
                                                         const auto &a) {
        if (dep == -1)return (LL) (tag == 5);
        if (up == 0 && zero == 0 && f[dep][tag] != -1)return f[dep][tag];
        int lim = a[dep];
        if (!up)lim = 9;
        LL ret = 0;
        for (int i = 0; i <= lim; i++) {
            ret += dp(dep - 1, up && i == lim, zero && i == 0, tran(tag, i), a);
        }
        if (up == 0 && zero == 0)f[dep][tag] = ret;
        return ret;
    };
    auto get = [&](LL x) {
        if (x == 0)return 0ll;
        std::vector<int> a;
        while (x > 0) {
            a.push_back((int) (x % 10));
            x /= 10;
        }
        int n = (int) a.size();
        return dp(n - 1, 1, 1, 0, a);
    };
    std::cout << get(r) - get(l - 1) << '\n';
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