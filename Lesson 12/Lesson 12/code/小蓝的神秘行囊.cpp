#include <bits/stdc++.h>

using LL = long long;
using ld = long double;
using unl = __int128;
using Pair = std::pair<int, int>;
#define inf 1'000'000'000

void solve(const int &Case) {
    int n, V, M;
    std::cin >> n >> V >> M;
    std::vector<int> v(n), m(n), w(n);
    for (int i = 0; i < n; i++)std::cin >> v[i] >> m[i] >> w[i];
    std::vector<std::vector<int>> f(V + 1, std::vector<int>(M + 1, -inf));
    f[0][0] = 0;
    for (int i = 0; i < n; i++) {
        auto g = f;
        std::vector<std::vector<int>>(V + 1, std::vector<int>(M + 1, -inf)).swap(f);
        for (int j = 0; j <= V; j++) {
            for (int k = 0; k <= M; k++) {
                f[j][k] = g[j][k];
                if (j >= v[i] && k >= m[i])f[j][k] = std::max(f[j][k], g[j - v[i]][k - m[i]] + w[i]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= V; i++) {
        for (int j = 0; j <= M; j++) {
            ans = std::max(ans, f[i][j]);
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