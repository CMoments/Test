#include <bits/stdc++.h>

using LL = long long;
using ld = long double;
using Pair = std::pair<ld, ld>;
#define inf 1'000'000'000

struct P {
    int x, y, c;
    // 当前状态为在 (x, y)，使用过 c 次咒语

    P(int x, int y, int c) : x(x), y(y), c(c) {}
};

void solve(const int &Case) {
    int n, m;
    std::cin >> n >> m;
    int sx, sy, ex, ey;
    std::cin >> sx >> sy >> ex >> ey;
    sx--, sy--, ex--, ey--;
    std::vector<std::string> a(n);
    for (auto &i: a)std::cin >> i;
    // 大小为 2 表示是否使用过咒语
    std::vector<std::vector<std::array<int, 2>>> vis(n, std::vector<std::array<int, 2>>(m));
    std::queue<P> q;
    q.emplace(sx, sy, 0);
    vis[sx][sy][0] = 1;
    const std::array<int, 4> dx{0, 0, 1, -1}, dy{1, -1, 0, 0};
    while (!q.empty()) {
        auto [x, y, c] = q.front(); // 取出队首状态
        q.pop();
        if (x == ex && y == ey) { // 如果已经到终点
            std::cout << "Yes\n";
            return;
        }
        for (int i = 0; i < 4; i++) { // 网格图 dfs/bfs 的范式
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
            if (a[nx][ny] != '#') {
                if (!vis[nx][ny][c]) { // 如果没遍历过
                    vis[nx][ny][c] = 1; // bfs 时 vis 的更新在这里，而 dfs 时 vis 的更新在最开头
                    q.emplace(nx, ny, c);
                }
            }
            else {
                if (c == 0) {
                    if (!vis[nx][ny][1]) {
                        vis[nx][ny][1] = 1;
                        q.emplace(nx, ny, 1);
                    }
                }
            }
        }
    }
    std::cout << "No\n";
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
