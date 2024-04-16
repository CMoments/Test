// 这里的 xor, and, or 都是位运算
// 1 xor 0 = 1, 1 xor 1 = 0
// 异或可以理解成不进位加法
// 区间和，区间异或和，要想到前缀和，虽然这题不太能这么做，但也得想到这一点
// x + y >= x xor y
// 如果 x + y = x xor y，意味着加法不能进位，x and y = 0
// 因为 x and y = 0，所以 x xor y 一定会多一些 1

#include <bits/stdc++.h>

using LL = long long;
using Pair = std::pair<int, int>;
#define inf 1'000'000'000

void solve(const int &Case) {
    int n;
    std::cin >> n;
    std::vector<int> a(n), zero(n + 1);
    // zero 是当前开始往后遇到的连续 0 数量
    for (auto &x: a)std::cin >> x;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == 0)zero[i] = zero[i + 1] + 1;
        else zero[i] = 0;
    }
    LL ans = 0;
    for (int l = 0; l < n; l++) {
        int r = l;
        int sum_xor = 0;
        while (r < n) {
            if (!a[r]) {
                r += zero[r];
            }
            else {
                if (sum_xor & a[r])break;
                sum_xor ^= a[r];
                r++; // 不超过 O(log A)
            }
        }
        ans += r - l;
    }
    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T = 1;
    for (int Case = 1; Case <= T; Case++)solve(Case);
    return 0;
}