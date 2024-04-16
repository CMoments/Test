#include <bits/stdc++.h>

using LL = long long;
using Pair = std::pair<int, int>;
#define inf 1'000'000'000

void solve(const int &Case) {
    int n, k;
    std::cin >> n >> k;
    std::vector<std::vector<Pair>> G(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;
        G[u].emplace_back(v, w), G[v].emplace_back(u, w);
    }
    int ans = 0;
    std::function<void(int, int, int)> dfs = [&](int x, int fax, int w) {
        if (x != 1 && w <= k)ans++;
        for (const auto &[tox, v]: G[x]) {
            if (tox == fax)continue;
            dfs(tox, x, w ^ v);
        }
    };
    dfs(1, 0, 0);
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