#include <bits/stdc++.h>

using LL = long long;
using ld = long double;
using unl = __int128;
using Pair = std::pair<int, int>;
#define inf 1'000'000'000

void solve(const int &Case) {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> G(n + 1);
    std::vector<int> hava_fa(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        G[v].push_back(u);
        hava_fa[u] = 1;
    }
    std::vector<int> sz(n + 1);
    std::function<void(int, int)> dfs = [&](int x, int fax) { // 求子树大小
        sz[x] = 1;
        for (const auto &tox: G[x]) {
            if (tox == fax)continue;
            dfs(tox, x);
            sz[x] += sz[tox];
        }
    };
    for (int i = 1; i <= n; i++) { // 找根，这题要求根没有父亲
        if (!hava_fa[i]) {
            dfs(i, 0);
            break;
        }
    }
    std::vector<int> id(n + 1);
    std::iota(id.begin(), id.end(), 0);
    std::sort(id.begin() + 1, id.end(), [&](int x, int y) {
        return sz[x] == sz[y] ? x < y : sz[x] > sz[y];
    });
    for (int i = 1; i <= n; i++) {
        if (id[i] == m) {
            std::cout << i << '\n';
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