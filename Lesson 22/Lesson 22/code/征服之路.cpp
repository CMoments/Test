// 正确性存疑

#include <bits/stdc++.h>

#include <utility>

using LL = long long;
using ull = unsigned long long;
using ld = long double;
using Pair = std::pair<int, int>;
#define inf 2'000'000'000

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

void solve(const int &Case) {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> G(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    std::vector<int> dep(n + 1);
    std::vector<int> A;
    std::vector<int> fl(n + 1);
    A.push_back(1);
    std::vector<int> mx(n + 1);
    std::function<void(int, int)> dfs_dep = [&](int x, int fax) {
        mx[x] = dep[x];
        for (const auto &tox: G[x]) {
            if (tox == fax)continue;
            dep[tox] = dep[x] + 1;
            dfs_dep(tox, x);
            mx[x] = std::max(mx[x], mx[tox]);
        }
    };
    dfs_dep(1, 0);
    std::function<void(int, int)> dfs = [&](int x, int fax) {
        std::sort(G[x].begin(), G[x].end(), [&](int a, int b) {
            return mx[a] < mx[b];
        });
        for (const auto &tox: G[x]) {
            if (tox == fax)continue;
            A.push_back(tox);
            dfs(tox, x);
            A.push_back(x);
            fl[x] = 1;
        }
    };
    dfs(1, 0);
    LL ans = 0;
    int cnt = 0;
    for (const auto &x: A) {
        if (!fl[x]) {
            ans += std::min(dep[x], cnt);
            cnt = 0;
        }
        cnt++;
    }
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