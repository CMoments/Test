// 一个基本的思路，设 f[l][r] 表示将 [l, r] 染色成功的最少操作数
// 转移想法是枚举断点 k(k = l, ..., r - 1), f[l][r] = min(f[l][k] + f[k + 1][r])
// 此时唯一没被枚举到的情况是染色时跨过了所有的断点，也就是对 [l, r] 直接染色
// 而假设左端点是 a[l], 如果右端点 a[r] != a[l]，而某个 a[k] = a[l]，此时染 [l, r] 不如染 [l, k]
// 也就是说只有当 a[l] = a[r] 时，直接染 [l, r] 才可能更优
// 而直接染 [l, r] 等价于将 [l, r - 1] 染完，所以此时 f[l][r] = f[l][r - 1]

#include <bits/stdc++.h>

using LL = long long;
using ld = long double;
using Pair = std::pair<int, int>;
#define inf 1'000'000'000

void solve(const int &Case) {
    std::string s;
    std::cin >> s;
    int n = (int) s.size();
    std::vector<std::vector<int>> f(n, std::vector<int>(n, inf));
    for (int i = 0; i < n; i++)f[i][i] = 1;
    for (int len = 1; len < n; len++) {
        for (int l = 0, r = len; r < n; l++, r++) {
            for (int k = l; k < r; k++) {
                f[l][r] = std::min(f[l][r], f[l][k] + f[k + 1][r]);
            }
            if (s[l] == s[r])f[l][r] = std::min(f[l][r], f[l][r - 1]);
        }
    }
    std::cout << f[0][n - 1] << '\n';
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