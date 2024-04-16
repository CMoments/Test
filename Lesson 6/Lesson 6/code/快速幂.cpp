#include <bits/stdc++.h>

using LL = long long;
using Pair = std::pair<int, int>;
#define inf 1'000'000'000

void solve(const int &Case) {
    int b, p, k;
    std::cin >> b >> p >> k;
    // 建议取模乘法用个函数写
    auto mul = [&](const int &x, const int &y) {
        return (int) ((LL) x * y % k);
    };
    auto qpow = [&](int x, int y) {
        int ret = 1;
        while (y > 0) {
            if (y & 1)ret = mul(ret, x);
            x = mul(x, x), y /= 2;
        }
        return ret;
    };
    std::cout << qpow(b, p) << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T = 1;
    for (int Case = 1; Case <= T; Case++)solve(Case);
    return 0;
}