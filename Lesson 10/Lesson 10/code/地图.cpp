#include <bits/stdc++.h>

using LL = long long;
using ld = long double;
using Pair = std::pair<ld, ld>;
#define inf 1'000'000'000

void solve(const int &Case) {
    int n, m, K;
    std::cin >> n >> m >> K;
    std::vector<std::string> a(n);
    for (auto &i: a)std::cin >> i;
    using state = std::array<std::array<LL, 2>, 6>;
    std::vector<std::vector<state>> f(n, std::vector<state>(m));
    if (n != 1)f[1][0][0][0] = 1;
    if (m != 1)f[0][1][0][1] = 1;
    // 0 down, 1 right
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '#' || (i == 0 && j == 0))continue;
            for (int k = 0; k <= K; k++) {
                for (int d = 0; d < 2; d++) {
                    if (f[i][j][k][d] == 0)continue;

                    // 不转向
                    int ni = i, nj = j;
                    if (d == 0)ni++;
                    else nj++;
                    // 转移到 (ni, nj)
                    if (ni < n && nj < m && a[ni][nj] != '#') {
                        f[ni][nj][k][d] += f[i][j][k][d];
                    }

                    ni = i, nj = j;

                    // 转向
                    if (d == 0)nj++; // 因为转了向，所以反一下
                    else ni++;
                    // 转移到 (ni, nj)
                    if (ni < n && nj < m && a[ni][nj] != '#' && k + 1 <= K) {
                        // x ^ 1 等价于 0 变 1 且 1 变 0 
                        f[ni][nj][k + 1][d ^ 1] += f[i][j][k][d];
                    }
                }
            }
        }
    }
    LL ans = 0;
    for (int i = 0; i <= K; i++) {
        ans += f[n - 1][m - 1][i][0] + f[n - 1][m - 1][i][1];
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