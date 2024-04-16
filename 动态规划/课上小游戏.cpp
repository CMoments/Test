#include <bits/stdc++.h>

using LL = long long;
using ld = long double;
using Pair = std::pair<int, int>;
#define inf 1'000'000'000'000'000ll

void solve(const int &Case) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto &i: a)std::cin >> i;
    for (int i = 0; i < n; i++)a.push_back(a[i]); // 倍长
    std::vector<std::vector<int>> f(n + n, std::vector<int>(n + n)), s(n + n, std::vector<int>(n + n));
    // s 就是区间乘积 mod 10
    for (int l = 0; l < n + n; l++) {
        s[l][l] = a[l];
        for (int r = l + 1; r < n + n; r++) {
            s[l][r] = s[l][r - 1] * a[r] % 10;
        }
    }
    for (int len = 1; len < n; len++) { // 区间 dp 一定是先枚举长度, 长度只用枚举到 n, 不用枚举到 2n
        for (int l = 0, r = l + len; r < n + n; l++, r++) { // 注意 r 要到 2n
            for (int k = l; k < r; k++) {
                f[l][r] = std::max(f[l][r], f[l][k] + f[k + 1][r] + s[l][k] * s[k + 1][r] / 10);
            }
        }
    }
    int ans = 0;
    for (int l = 0, r = l + n - 1; r < n + n; l++, r++) { // 枚举所有长度为 n 的区间
        // 因为总有环上相邻的数不是直接合并的，所以答案一定存在于所有长度为 n 的区间
        ans = std::max(ans, f[l][r]);
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