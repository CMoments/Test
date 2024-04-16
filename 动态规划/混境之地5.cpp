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
    int n, m, k;
    std::cin >> n >> m >> k;
    int sx, sy, ex, ey;
    std::cin >> sx >> sy >> ex >> ey;
    sx--, sy--, ex--, ey--;
    std::vector<std::vector<int>> h(n, std::vector<int>(m));
    for (auto &i: h)for (auto &j: i)std::cin >> j;
    std::vector<std::vector<std::array<int, 2>>> vis(n, std::vector<std::array<int, 2>>(m));
    std::queue<P> q;
    q.emplace(sx, sy, 0);
    vis[sx][sy][0] = 1;
    const std::array<int, 4> dx{0, 0, 1, -1}, dy{1, -1, 0, 0};
    while (!q.empty()) {
        auto [x, y, c] = q.front();
        q.pop();
        if (x == ex && y == ey) {
            std::cout << "Yes\n";
            return;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
            if (h[nx][ny] <= h[x][y]) {
                if (!vis[nx][ny][c]) {
                    vis[nx][ny][c] = 1;
                    q.emplace(nx, ny, c);
                }
            } else {
                if (c == 0) {
                    if (h[nx][ny] <= h[x][y] + k && !vis[nx][ny][1]) {
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