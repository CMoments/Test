#include <bits/stdc++.h>

using LL = long long;
using ld = long double;
using Pair = std::pair<ld, ld>;
#define inf 1'000'000'000

struct P {
    int x, y;

    P(int x, int y) : x(x), y(y) {}
};

void solve(const int &Case) {
    int n, m;
    std::cin >> n >> m;
    int sx, sy, ex, ey;
    std::cin >> sx >> sy >> ex >> ey;
    sx--, sy--, ex--, ey--;
    std::vector<std::string> a(n);
    for (auto &x: a)std::cin >> x;
    std::vector<std::vector<int>> vis(n, std::vector<int>(m));
    std::queue<P> q;
    q.emplace(sx, sy);
    vis[sx][sy] = 1;
    const std::array<int, 4> dx{0, 0, 1, -1}, dy{1, -1, 0, 0};
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        if (x == ex && y == ey) {
            std::cout << "Yes\n";
            return;
        }
        int c = a[x][y] - 'A';
        c = (c + 1) % 4;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
            int d = a[nx][ny] - 'A';
            if (c == d) {
                if (!vis[nx][ny]) {
                    vis[nx][ny] = 1;
                    q.emplace(nx, ny);
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