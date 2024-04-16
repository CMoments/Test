#include <bits/stdc++.h>

using LL = long long;
using ld = long double;
using Pair = std::pair<int, int>;
#define inf 1'000'000'000

void solve(const int &Case) {
    int n;
    std::cin >> n;
    std::vector<std::vector<Pair>> G(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }
    std::vector<std::array<int, 2>> f(n + 1);
    auto ch = [&](const int &x, const int &v) {
        // 次大值怎么求？
        // if v >= 最大值 then 次大值 = 最大值，最大值 = v then 次大值 = max(次大值, v)
        if (v >= f[x][0]) {
            f[x][1] = f[x][0];
            f[x][0] = v;
        } else if (v > f[x][1]) {
            f[x][1] = v;
        }
    };
    std::function<void(int, int)> dfs = [&](int x, int fax) {
        for (const auto &[tox, val]: G[x]) {
            if (tox == fax)continue;
            dfs(tox, x);
            ch(x, f[tox][0] + val);
        }
    };
    dfs(1, 0);
    LL ans = 0;
    std::function<void(int, int)> rdfs = [&](int x, int fax) {
        ans = std::max(ans, (LL) f[x][0] * f[x][1]);
        for (const auto &[tox, val]: G[x]) {
            if (tox == fax)continue;
            int v = f[x][0] == f[tox][0] + val ? f[x][1] : f[x][0];
            ch(tox, v + val);
            rdfs(tox, x);
        }
    };
    rdfs(1, 0);
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