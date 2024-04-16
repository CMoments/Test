#include <bits/stdc++.h>

using LL = long long;
using ld = long double;
using Pair = std::pair<int, int>;
#define inf 1'000'000'000'000'000'000ll

void solve(const int &Case) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    int V = 0;
    for (auto &i: a)std::cin >> i, V += i;
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
    if (f[V / 2] && V % 2 == 0) { // V 要求正好分割成两半，所以要判断是否为偶数
        std::cout << "yes\n";
    }
    else {
        std::cout << "no\n";
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