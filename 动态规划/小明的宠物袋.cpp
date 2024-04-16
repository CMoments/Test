// 对于第 i 层第 j 个格子能不能放宠物，我们肯定需要知道第 i - 1 层第 j 个格子有没有放宠物，且第 i 层第 j - 1 个格子有没有放宠物
// 状压，状态 T 的第 j 位表示上一层的第 j 个格子有没有放宠物，如果有是 1，没有就是 0，此时 S 就是 m 位二进制数
// f[i][T] 表示处理了前 i 层，第 i 层状态为 T 的最大宠物数量
// 我们枚举了当前层状态为 T，上一层状态为 S，根据上述信息，我们有以下几个限制：
// 1. 如果 S[j] = 1, 此时 T[j] 必须为 0，从二进制角度来看，就是不能有同一位同时为 1，即 T and S = 0
// 2. 如果 T[j] = 1, 此时 T[j + 1] 必须为 0，这启发我们预处理出合法的状态 T，即暴力枚举所有 T, 判断是否满足条件
// 3. 如果 a[i][j] = 1, 此时 T[j] 必须为 0，从二进制角度来看，就是不能有同一位同时为 1, 即 T and a[i] = 0
// 重新捋一下三个限制:
// 1. T and S = 0
// 2. T[j] and T[j + 1] = 0
// 3. T and a[i] = 0

#include <bits/stdc++.h>

using LL = long long;
using ld = long double;
using Pair = std::pair<int, int>;
#define inf 1'000'000'000

void solve(const int &Case) {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        int S = 0;
        for (int j = 0; j < m; j++) {
            int x;
            std::cin >> x;
            S = S * 2 | x;
        }
        a[i] = S;
    }
    std::vector<int> ban(1 << m);
    for (int S = 0; S < 1 << m; S++) { // 预处理出所有满足 T[j] and T[j + 1] = 0 的 T
        // ban[S] = 1 表示不满足
        for (int i = 0; i < m - 1; i++) {
            if ((S >> i & 1) && (S >> (i + 1) & 1)) {
                ban[S] = 1;
                break;
            }
        }
    }
    std::vector<int> f(1 << m, -1);
    f[0] = 0;
    for (int i = 0; i < n; i++) {
        auto g = f;
        std::vector<int>(1 << m, -1).swap(f);
        for (int T = 0; T < 1 << m; T++) {
            if (T & a[i] || ban[T])continue; // 合法的 T 要求 T and a[i] = 0 而且 ban[T] = 0
            // S and T = 0
            // (1 << m) - 1 为 m 位二进制数，且每一位都是 1
            // T xor ((1 << m) - 1) 等价于 T 每一位都取反, 即 0 变 1, 1 变 0
            // 此时 S and T = 0 等价于 S 是 T xor ((1 << m) - 1) 的子集
            // 然后枚举子集
            // __builtin_popcount(x) 表示的是 x 二进制位中 1 的个数，记不住这个函数可以自己提前预处理
            int S = T ^ ((1 << m) - 1), v = __builtin_popcount(T);
            for (int nS = S; nS > 0; nS = (nS - 1) & S) { // 枚举 nS 是 S 的子集，且按照字典序降序，建议记住
                if (g[nS] == -1)continue;
                f[T] = std::max(f[T], g[nS] + v);
            }
            f[T] = std::max(f[T], g[0] + v); // 注意上面的代码中，nS 不能等于 0，所以这里再特殊处理一下
        } // 这一串代码时间复杂度是 O(3 ^ m)
        // 参考位运算那一章节
    }
    std::cout << *std::max_element(f.begin(), f.end()) << '\n';
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