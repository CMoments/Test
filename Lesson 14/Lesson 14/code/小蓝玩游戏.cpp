// f[i][j] 
// = (f[i][j] + 1) * i / n * j / m + (f[i + 1][j] + 1) * (n - i) / n * j / m 
//      + (f[i][j + 1] + 1) * i / n * (m - j) / m + (f[i + 1][j + 1] + 1) * (n - i) / n * (m - j) / m
// f[i][j] 
// = (f[i][j + 1] * i * (m - j) + f[i + 1][j] * j * (n - i) 
//      + f[i + 1][j + 1] * (n - i) * (m - j) + n * m) / (n * m - i * j)

#include <bits/stdc++.h>

using LL = long long;
using ld = long double;
using unl = __int128;
using Pair = std::pair<int, int>;
#define inf 1'000'000'000'000'000ll

void solve(const int &Case) {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<double>> f(n + 1, std::vector<double>(m + 1));
    for (int i = n; i >= 0; i--) {
        for (int j = m; j >= 0; j--) {
            if (i == n && j == m)continue;
            if (j < m)f[i][j] += f[i][j + 1] * i * (m - j);
            if (i < n)f[i][j] += f[i + 1][j] * j * (n - i);
            if (i < n && j < m)f[i][j] += f[i + 1][j + 1] * (n - i) * (m - j);
            f[i][j] = (f[i][j] + n * m) / (n * m - i * j);
        }
    }
    std::cout << std::fixed << std::setprecision(4) << f[0][0] << '\n';
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