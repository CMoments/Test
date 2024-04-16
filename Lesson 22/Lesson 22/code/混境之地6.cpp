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
    for (auto &s: a)std::cin >> s;
    a[ex][ey] = a[sx][sy] = '.';
    std::vector<std::vector<std::array<int, 2>>> vis(n, std::vector<std::array<int, 2>>(m));
    std::queue<P> q;
    q.emplace(sx, sy, 0);
    vis[sx][sy][0] = 1;
    const std::array<int, 4> dx{0, 0, 1, -1}, dy{1, -1, 0, 0};
    while (!q.empty()) {
        auto [x, y, c] = q.front();
        q.pop();
        if (x == ex && y == ey) {
            if (c == 1) {
                std::cout << vis[x][y][c] - 1 << '\n';
                return;
            }
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
            if (a[nx][ny] == '#')continue;
            int d = c;
            if (a[nx][ny] == 'k')d = 1;
            if (vis[nx][ny][d] == 0) {
                q.emplace(nx, ny, d);
                vis[nx][ny][d] = vis[x][y][c] + 1;
            }
        }
    }
    std::cout << "-1\n";
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