// 如果根固定，可以很简单地 dp 一下
// 设 mx_x 表示 x 的子树内所有点到 x 的最深距离
// 转移显然是 mx_x = max_{z\in son_x} mx_z + 1
// 但现在换根了，怎么办呢
// 假设从 x 换到 y，可以发现只有 x 和 y 的转移式子变了，其他都不变
// 现在还是以 x 为根，假设 x 儿子中不包含 y 的集合是 Son_x，y 儿子集合是 Son_y(因为还没换根，所以不包含 x)
// 换根前，mx_x = max(max_{z\in Son_x} mx_z, mx_y) + 1, mx_y = max_{z\in Son_y} mx_z + 1
// 换根后，mx'_x = max_{z\in Son_x} mx_z + 1, mx'_y = max(max_{z\in Son_y} mx_z, mx'_x) + 1
// 记录 mx_x 为极大值，smx_x 为次大值即可
// if mx_y + 1 == mx_x then mx'_x = smx_x else mx'_x = mx_x
// mx'_y = max(mx_y, mx'_x)

#include <bits/stdc++.h>

using LL = long long;
using ld = long double;
using Pair = std::pair<int, int>;
#define inf 1'000'000'000

void solve(const int &Case) {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> G(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)std::cin >> a[i];
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
        for (const auto &tox: G[x]) {
            if (tox == fax)continue;
            dfs(tox, x);
            ch(x, f[tox][0] + a[tox]);
        }
    };
    dfs(1, 0);
    int ans = 0;
    std::function<void(int, int)> rdfs = [&](int x, int fax) {
        ans = std::max(ans, f[x][0] + f[x][1] + a[x]);
        for (const auto &tox: G[x]) {
            if (tox == fax)continue;
            int v = f[x][0] == f[tox][0] + a[tox] ? f[x][1] : f[x][0];
            ch(tox, v + a[x]);
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