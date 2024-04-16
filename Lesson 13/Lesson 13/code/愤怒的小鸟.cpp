#include <bits/stdc++.h>

using LL = long long;
using ld = long double;
using Pair = std::pair<double, double>;
#define inf 1'000'000'000'000'000'000ll

void solve(const int &Case) {
    int n, m;
    std::cin >> n >> m;
    std::vector<Pair> a(n);
    for (auto &[x, y]: a)std::cin >> x >> y;
    // p[i][j] 表示经过 i 号🐷和 j 号🐷的抛物线经过的🐷的编号
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)continue;
            // A x^2 + Bx = y, A X^2 + BX = Y
            // B = (y - Ax^2) / x, B = (Y - AX^2) / X
            // (y - Ax^2) / x = (Y - AX^2) / X
            // (y - Ax^2)X = (Y - AX^2)x
            // yX - Ax^2X = Yx - AX^2x
            // yX - Yx = Ax^2X - AX^2x
            // yX - Yx = A(x^2X - X^2x)
            // A = (yX - Yx) / (x^2X - X^2x)
            auto [x, y] = a[i];
            auto [X, Y] = a[j];
            if (x == X)continue;
            double A = (y * X - Y * x) / (x * x * X - X * X * x);
            if (A >= -1e-6)continue; // 精度问题
            double B = (y - A * x * x) / x;
            for (int k = 0; k < n; k++) {
                auto [x0, y0] = a[k];
                if (std::abs(A * x0 * x0 + B * x0 - y0) < 1e-6)p[i][j] |= 1 << k;
            }
        }
    }
    std::vector<int> low(1 << n); // low[x] 表示 x 最低位的 0
    for (int S = 0; S < 1 << n; S++) {
        for (int i = 0; i < n; i++) {
            if (S >> i & 1);
            else {
                low[S] = i;
                break;
            }
        }
    }
    std::vector<int> f(1 << n, n);
    f[0] = 0;
    for (int S = 0; S < (1 << n) - 1; S++) {
        int x = low[S]; // 只枚举经过 x 的所有抛物线
        for (int i = 0; i < n; i++) {
            if (i == x)continue;
            f[S | p[x][i]] = std::min(f[S | p[x][i]], f[S] + 1);
        }
        f[S | (1 << x)] = std::min(f[S | (1 << x)], f[S] + 1);
    }
    std::cout << f[(1 << n) - 1] << '\n';
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