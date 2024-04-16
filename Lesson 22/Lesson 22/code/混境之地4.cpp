#include <bits/stdc++.h>

using LL = long long;
using ld = long double;
using Pair = std::pair<ld, ld>;
#define inf 1'000'000'000

struct P {
    int x, y, c;

    P(int x, int y, int c) : x(x), y(y), c(c) {}
};

void solve(const int &Case) {
    int n, m;
    std::cin >> n >> m;
    int sx, sy, ex, ey;
    std::cin >> sx >> sy >> ex >> ey;
    sx--, sy--, ex--, ey--;
    std::vector<std::string> a(n);
    for (auto &x: a)std::cin >> x;
    a[sx][sy] = a[ex][ey] = '.';
    int E;
    std::cin >> E;
    std::vector<std::vector<std::array<int, 2>>> vis(n, std::vector<std::array<int, 2>>(m, {-1, -1}));
    std::queue<P> q;
    q.emplace(sx, sy, 0);
    vis[sx][sy][0] = 0;
    const std::array<int, 4> dx{0, 0, 1, -1}, dy{1, -1, 0, 0};
    int ans = inf;
    while (!q.empty()) {
        auto [x, y, c] = q.front();
        q.pop();
        if (x == ex && y == ey) {
            if (c == 0) {
                if (E >= vis[x][y][0])ans = std::min(ans, vis[x][y][0]);
            }
            else {
                int p = std::max(vis[x][y][1] - E, 0);
                ans = std::min(ans, vis[x][y][1] + p);
            }
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
            if (a[nx][ny] == '#')continue;
            int d;
            if (c == 0 && a[nx][ny] == 'V') {
                d = 1;
            }
            else d = c;
            if (vis[nx][ny][d] != -1)continue;
            q.emplace(nx, ny, d);
            vis[nx][ny][d] = vis[x][y][c] + 1;
        }
    }
    if (ans != inf)std::cout << ans << '\n';
    else std::cout << "No\n";
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