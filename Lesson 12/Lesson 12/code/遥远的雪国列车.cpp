// 二维数点
// 列车是 [L, R]，询问是 [l, r]
// 将列车看作二维平面上一个点 (L, R)
// 询问看成一个矩形，x 轴坐标是 [l, r]，y 轴坐标是 [l, r]
// 题目等价于询问矩形内有多少个点
// 二维前缀和

#include <bits/stdc++.h>

using LL = long long;
using ld = long double;
using unl = __int128;
using Pair = std::pair<int, int>;
#define inf 1'000'000'000'000'000ll

void solve(const int &Case) {
    int n, m, q;
    std::cin >> n >> m >> q;
    std::vector<std::vector<int>> f(n, std::vector<int>(n));
    while (m--) {
        int l, r;
        std::cin >> l >> r;
        l--, r--;
        f[l][r]++;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            f[i][j] += f[i][j - 1];
        }
    }
    for (int j = 0; j < n; j++) {
        for (int i = 1; i < n; i++) {
            f[i][j] += f[i - 1][j];
        }
    }
    while (q--) {
        int l, r;
        std::cin >> l >> r;
        l--, r--;
        std::cout << f[r][r] - f[l - 1][r] - f[r][l - 1] + f[l - 1][l - 1] << '\n';
    }
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