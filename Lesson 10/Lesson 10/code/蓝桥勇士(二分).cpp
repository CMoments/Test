// 给出 n 个数，挑出最多的数，使得下标在上升的同时，值也在上升

#include <bits/stdc++.h>

using LL = long long;
using ld = long double;
using Pair = std::pair<int, int>;
#define inf 1'000'000'000

void solve(const int &Case) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto &i:a)std::cin >> i;
    std::vector<int> f(n), g(n + 1, inf + 1);
    g[0] = 0;
    int L = 0;
    // L 表示当前的最长上升子序列
    // g_i 表示 f = i 中最小的 a，即 g 的值是 a
    // 根据之前分析的性质，g 是递增的，于是具有二分性
    // 我们考虑计算 f_i
    // 此时我们肯定想找到一个 j < i，使得 a_j < a_i 且 f_j 是所有合法 j 中最大的
    // 我们二分 g，获得第一个 m，满足 g_m < a_i
    // 此时意味着满足 j < i，且 a_j < a_i 的所有 j 中，最大的 f_j = m
    // 所以 f_i = m + 1，反过来更新 g
    for (int i = 0; i < n; i++) {
        int l = 0, r = L, ret = 0;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (g[mid] < a[i]) {
                ret = mid;
                l = mid + 1;
            } else r = mid - 1;
        }
        f[i] = ret + 1;
        g[f[i]] = std::min(g[f[i]], a[i]);
        if (ret == L)L++;
    }
    std::cout << L << '\n';
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