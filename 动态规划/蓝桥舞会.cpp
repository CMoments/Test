// 最大点独立集

#include <bits/stdc++.h>

using LL = long long;
using ld = long double;
using unl = __int128;
using Pair = std::pair<int, int>;
#define inf 1'000'000'000

void solve(const int &Case) {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)std::cin >> a[i];
    std::vector<std::vector<int>> G(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    std::vector<std::array<LL, 2>> f(n + 1);
    // 1 choose
    std::function<void(int, int)> dfs = [&](int x, int fax) {
        f[x][1] = a[x];
        for (const auto &tox: G[x]) {
            if (tox == fax)continue;
            dfs(tox, x);
            f[x][0] += std::max(f[tox][0], f[tox][1]);
            f[x][1] += f[tox][0];
        }
    };
    dfs(1, 0);
    std::cout << std::max(f[1][0], f[1][1]) << '\n';
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