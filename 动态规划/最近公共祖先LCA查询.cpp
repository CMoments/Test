// 建议多抄多背

#include <bits/stdc++.h>

using LL = long long;
using Pair = std::pair<int, int>;
#define inf 1'000'000'000

void solve(const int &Case) {
    int n;
    std::cin >> n;
    // 建图和树都建议按照下面的方式
    std::vector<std::vector<int>> G(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        G[u].push_back(v), G[v].push_back(u);
    }
    // 倍增数组
    std::vector<std::array<int, 21>> F(n + 1);
    std::vector<int> dep(n + 1);
    // 当作模板背下来
    std::function<void(int, int)> dfs = [&](int x, int fax) {
        F[x][0] = fax;
        // x 跳 2 ^ i 等价于 x 先跳 2 ^ {i - 1} 再跳 2 ^ {i - 1}
        for (int i = 1; i <= 20; i++)F[x][i] = F[F[x][i - 1]][i - 1];
        for (const auto &tox: G[x]) {
            if (tox == fax)continue;
            dep[tox] = dep[x] + 1;
            dfs(tox, x);
        }
    };
    dfs(1, 0);
    auto glca = [&](int x, int y) {
        if (dep[x] < dep[y])std::swap(x, y);
        // 先将 x 跳到和 y 相同的深度
        int d = dep[x] - dep[y];
        for (int i = 20; i >= 0; i--)if (d >> i & 1)x = F[x][i];
        if (x == y)return x;
        // 循环顺序不能变，必须倒序
        for (int i = 20; i >= 0; i--) {
            if (F[x][i] != F[y][i]) {
                x = F[x][i];
                y = F[y][i];
            }
        }
        return F[x][0];
    };
    int q;
    std::cin >> q;
    while (q--) {
        int x, y;
        std::cin >> x >> y;
        std::cout << glca(x, y) << '\n';
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T = 1;
    for (int Case = 1; Case <= T; Case++)solve(Case);
    return 0;
}