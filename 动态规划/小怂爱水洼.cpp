// 将四连通网格图连边，等价于求最大权值和连通块

// 四连通(十)网格图 dx = {0, 0, 1, -1}, dy = {1, -1, 0, 0}
// 八连通块(米)网格图 dx = {0, 0, 1, 1, 1, -1, -1, -1}, dy = {1, -1, 0, 1, -1, 0, 1, -1}
// 马(日)网格图 dx = {1, 1, -1, -1, 2, 2, -2, -2}, dy = {2, -2, 2, -2, 1, -1, 1, -1}

#include <bits/stdc++.h>

using LL = long long;
using ld = long double;
using Pair = std::pair<ld, ld>;
#define inf 1'000'000'000

void solve(const int &Case) {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> a(n, std::vector<int>(m));
    for (auto &i: a)for (auto &j: i)std::cin >> j;
    const std::array<int, 4> dx = {0, 0, 1, -1}, dy = {1, -1, 0, 0};
    // 假设现在在 (x, y)
    // (x + dx[0], y + dy[0]) = (x, y + 1)
    // (x + dx[1], y + dy[1]) = (x, y - 1)
    // (x + dx[2], y + dy[2]) = (x + 1, y)
    // (x + dx[3], y + dy[3]) = (x - 1, y)
    std::vector<std::vector<int>> vis(n, std::vector<int>(m));
    LL ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j] || a[i][j] == 0)continue;
            LL cnt = 0;
            std::function<void(int, int)> dfs = [&](int x, int y) {
                cnt += a[x][y];
                vis[x][y] = 1; // 每个点只能遍历一次
                // 网格图 dfs/bfs 的经典写法
                for (int k = 0; k < 4; k++) {
                    int nx = x + dx[k], ny = y + dy[k]; // (nx, ny) 是从 (x, y) 走到的下一个点
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m || a[nx][ny] == 0)continue; // 判断是否越界或者不合法
                    if (vis[nx][ny])continue;
                    dfs(nx, ny);
                }
            };
            dfs(i, j);
            ans = std::max(ans, cnt);
        }
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