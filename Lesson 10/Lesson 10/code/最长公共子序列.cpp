// f[i][j] = max_{k < i, l < j} f[k][l] + 1
// S[i][j] = max_{k <= i, l <= j} S[k][l]
// if a[i] == b[j] then f[i][j] = S[i - 1][j - 1] + 1
// else f[i][j] = 0
// S[i][j] = max(S[i - 1][j], S[i][j - 1], f[i][j])
// 对于 S[i][j] 而言，它只从 S[i - 1][j] 和 S[i][j - 1] 转移，发现都是要么 i 小，要么 j 小
// 所以转移顺序就是 i 从小到大，j 从小到大
// 另一方面，S[i] 只与 S[i - 1] 和 S[i] 有关，所以仍然可以滚动数组


#include <bits/stdc++.h>

using LL = long long;
using ld = long double;
using Pair = std::pair<int, int>;
#define inf 1'000'000'000

void solve(const int &Case) {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n);
    for (auto &i:a)std::cin >> i;
    std::vector<int> b(m);
    for (auto &i:b)std::cin >> i;
    std::vector<int> f(m);
    for (int i = 0; i < n; i++) {
        auto g = f;
        std::vector<int>(m + 1).swap(f);
        // f[i] = S[i]
        for (int j = 0; j < m; j++) {
            // S[i][j] = S[i - 1][j]
            f[j] = g[j];
            // S[i][j] = max(S[i - 1][j], S[i][j - 1])
            if (j > 0)f[j] = std::max(f[j], f[j - 1]);
            // S[i][j] = max(S[i - 1][j], S[i][j - 1], f[i][j] = S[i - 1][j - 1] + 1 = g[j - 1] + 1)
            if (a[i] == b[j])f[j] = std::max(f[j], g[j - 1] + 1); 
        }
    }
    std::cout << f[m - 1] << '\n';
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