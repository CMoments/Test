// 我们想要把一种有 s 个的物品拆分成若干个物品，使得它们的组合能表达出 [0, s] 内所有整数个物品
// 最最最最简单的思路就是将 s 拆成 s 个 1，此时就是物品种类数为 \sum_{i=1}^n s_i 的 01 背包
// 但信息是冗余的，因为此时我们拆分成了 s 种物品，表达了 s + 1 的信息量，但是理论上 s 种物品能表示出 2^s 的信息量 (即所有子集)
// 所以我们就想要 s 种物品去表达 O(2^s) 的信息，所以理论对于一种有 s 个的物品，我们应该只用拆分成 O(log s) 种物品即可

#include <bits/stdc++.h>

using LL = long long;
using ld = long double;
using unl = __int128;
using Pair = std::pair<int, int>;
#define inf 1'000'000'000

void solve(const int &Case) {
    int n, V;
    std::cin >> n >> V;
    std::vector<int> v, w;
    for (int i = 0; i < n; i++) {
        int vi, wi, si;
        std::cin >> wi >> vi >> si;
        for (int j = 1; j <= si; j *= 2) { // 枚举 2 的幂次
            v.push_back(vi * j);
            w.push_back(wi * j);
            si -= j;
        }
        if (si > 0) { // 剩余一点点为 x
            v.push_back(vi * si);
            w.push_back(wi * si);
        }
    }
    std::vector<int> f(V + 1, -inf);
    f[0] = 0;
    int m = (int) v.size();
    for (int i = 0; i < m; i++) {
        auto g = f;
        std::vector<int>(V + 1, -inf).swap(f);
        for (int j = 0; j <= V; j++) {
            f[j] = g[j];
            if (j >= w[i])f[j] = std::max(f[j], g[j - w[i]] + v[i]);
        }
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