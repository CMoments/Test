#include <bits/stdc++.h>

using LL = long long;
using ld = long double;
using Pair = std::pair<int, int>;
#define inf 1'000'000'000'000'000'000ll

void solve(const int &Case) {
    int n, V;
    std::cin >> V >> n;
    std::vector<int> a(n);
    for (auto &x: a)std::cin >> x;
    std::vector<int> f(V + 1);
    f[0] = 1;
    for (const auto &x: a) {
        auto g = f;
        std::vector<int>(V + 1).swap(f);
        for (int i = 0; i <= V; i++) {
            f[i] = g[i];
            if (i - x >= 0)f[i] |= g[i - x];
        }
    }
    for (int i = V; i >= 0; i--) { // 枚举能凑出来的小于等于 V 的最大体积是多少
        if (f[i]) {
            std::cout << V - i << '\n';
            return;
        }
    }
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