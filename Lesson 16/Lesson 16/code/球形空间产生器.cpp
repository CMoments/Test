#include <bits/stdc++.h>

using LL = long long;
using Pair = std::pair<int, int>;

void solve(const int &Case) {
    int n;
    std::cin >> n;
    std::vector<std::vector<double>> a(n + 1, std::vector<double>(n)), c(n, std::vector<double>(n));
    std::vector<double> b(n);
    const double eps=1e-8;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            c[i][j] = 2 * (a[i][j] - a[i + 1][j]);
            b[i] += a[i][j] * a[i][j] - a[i + 1][j] * a[i + 1][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (std::fabs(c[j][i]) > eps) {
                for (int k = 0; k < n; k++) {
                    std::swap(c[i][k], c[j][k]);
                }
                std::swap(b[i], b[j]);
            }
        }
        for (int j = 0; j < n; j++) {
            if (i == j)continue;
            double rate = c[j][i] / c[i][i];
            for (int k = i; k < n; k++) {
                c[j][k] -= c[i][k] * rate;
            }
            b[j] -= b[i] * rate;
        }
    }
    for (int i = 0; i < n; i++) {
        b[i] /= c[i][i];
    }
    for (int i = 0; i < n; i++) {
        std::cout << std::fixed << std::setprecision(3) << b[i] << " ";
    }
    std::cout << '\n';
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