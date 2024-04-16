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
    std::vector<std::string> a(n);
    for (auto &x: a)std::cin >> x;
    std::vector<std::vector<int>> vis(n, std::vector<int>(n));
    std::queue<Pair> q;
    q.emplace(0, 0);
    vis[0][0] = 1;
    const std::array<int, 4> dx{1, -1, 0, 0};
    const std::array<int, 4> dy{0, 0, 1, -1};
    const std::array<int, 3> d{1, -1, 0};
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n)continue;
            if (a[nx][ny] == 'X')continue;
            if (vis[nx][ny])continue;
            vis[nx][ny] = 1;
            q.emplace(nx, ny);
        }
    }
    if (!vis[n - 1][n - 1]) {
        std::cout << 0 << '\n';
        return;
    }
    auto bfs = [&](const int &sx, const int &sy, const int &c) {
        q.emplace(sx, sy);
        vis[sx][sy] = c;
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int nx = x + d[i], ny = y + d[j];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= n)continue;
                    if (a[nx][ny] != 'X')continue;
                    if (vis[nx][ny])continue;
                    vis[nx][ny] = c; // 每个点所属边缘的编号
                    q.emplace(nx, ny);
                }
            }
        }
    };
    for (int i = 0; i < n; i++) {
        if (a[0][i] == 'X') {
            bfs(0, i, 2);
        }
        if (a[i][0] == 'X') {
            bfs(i, 0, 3);
        }
        if (a[n - 1][i] == 'X') {
            bfs(n - 1, i, 4);
        }
        if (a[i][n - 1] == 'X') {
            bfs(i, n - 1, 5);
        }
    }
    a[0][0] = a[n - 1][n - 1] = 'O';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 'O') {
                std::array<int, 6> A{};
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        int ni = i + d[k], nj = j + d[l];
                        if (ni < 0 || nj < 0 || ni >= n || nj >= n) {
                            continue;
                        }
                        A[vis[ni][nj]] = 1;
                    }
                }
                if (i == 0 || j == n - 1) {
                    for (int k = 2; k < 6; k++) {
                        if (k != 5 && k != 2 && A[k]) {
                            std::cout << 1 << '\n';
                            return;
                        }
                    }
                }
                if (j == 0 || i == n - 1) {
                    for (int k = 2; k < 6; k++) {
                        if (k != 4 && k != 3 && A[k]) {
                            std::cout << 1 << '\n';
                            return;
                        }
                    }
                }
                for (int k = 2; k < 6; k++) {
                    for (int l = k + 1; l < 6; l++) {
                        if (A[k] && A[l] && k + l != 7) {
                            std::cout << 1 << '\n';
                            return;
                        }
                    }
                }
            }
        }
    }
    std::cout << 2 << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T = 1;
    std::cin >> T;
    for (int Case = 1; Case <= T; Case++)solve(Case);
    return 0;
}