#include <bits/stdc++.h>

using LL = long long;
using ld = long double;
using Pair = std::pair<int, int>;
#define inf 1'000'000'000

void solve(const int &Case) {
    int n, V;
    std::cin >> n >> V;
    std::vector<Pair> a(n);
    for (auto &[x, y]: a)std::cin >> x >> y;
    std::vector<int> f(V + 1, -inf);
    f[0] = 0;
    for (const auto &[x, y]: a) {
        auto g = f;
        std::vector<int>(V + 1, -inf).swap(f);
        for (int i = 0; i <= V; i++) {
            f[i] = g[i];
            if (i >= x)f[i] = std::max(f[i], g[i - x] + y);
        }
    }
    std::cout << *std::max_element(f.begin(), f.end()) << '\n';
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