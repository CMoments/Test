#include <bits/stdc++.h>

using LL = long long;
using Pair = std::pair<int, int>;
#define inf 1'000'000'000

void solve(const int &Case) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto &i: a)std::cin >> i;
    int cnt = 0;
    // 枚举集合，此时 S 的每一位表示第 i 个数是加还是减
    for (int S = 0; S < 1 << n; S++) {
        int p = 0;
        // 求第 i 位是加还是减
        for (int i = 0; i < n; i++) {
            // S >> i & 1 的意思是先做 S >> i，再 & 1，含义是 S 的第 i 位是不是 1
            // S >> i 等价于 S / 2 ^ i 下取整，意味着去除了最后的 i 位，此时个位数 (二进制) 是原数第 i 位
            // x & 1 等价于与 1 取 and，也就是只有 x 的个位与 1 做了 and，即 x 的个位数是不是 1
            if (S >> i & 1)p += a[i];
            else p -= a[i];
        }
        if (p % 7 == 0)cnt++;
    }
    double ans = (double) cnt / (1 << n);
    ans = std::round(ans * 1e4) / 1e4;
    std::cout << std::fixed << std::setprecision(4) << ans << '\n';
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

// 枚举 [n] 集合的全集，即枚举所有 2 ^ n 的子集
/*
for (int S = 0; S < 1 << n; S++)
此时 S 就是所有 2 ^ n 的子集
时间复杂度 O(2 ^ n)
*/

// 枚举 [n] 集合的子集的子集，即枚举所有 2 ^ n 的子集的子集 (很重要，后面状压 dp 会用到)
/*
方法一：
for (int S = 0; S < 1 << n; S++) {
    for (int T = 0; T < S; T++) {
        // (T & S) != T 表示的是 T 不是 S 的子集
        if ((T & S) != T)continue;
    }
}
此时 (S, T) 中，S 的枚举的子集，T 是 S 的子集
时间复杂度 O(4 ^ n)

方法二：
for (int S = 0; S < 1 << n; S++) {
    for (int T = S; T > 0; T = (T - 1) & S) {
    }
}
此时 (S, T) 中，S 的枚举的子集，T 是 S 的子集，而且此时枚举顺序中 T 是降序
时间复杂度 O(3 ^ n)，证明方法考虑 1 的出现贡献
*/

// lowbit(x) = x & (-x) ，可以自行了解，后面再 BIT (树状数组) 会用到