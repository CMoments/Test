// 看到最大的最小或者最小的最大，一定一定一定一定一定要考虑二分
// 这道题要求的是最大的最小，二分最小值是多少，于是你就需要所有人都大于等于这个二分的值，那么你就想知道所有人到达这个最小值需要消耗多少

// 2 2 10
// 1 2
// 1 5
// 2 9

// 假设答案是 1，此时两个人力量值都大于等于 1，所以不需要消耗精力，合法
// 假设答案是 2，第一个人需要通过训练使得力量值大于等于 2，给它训练计划一即可，消耗 2 点体力，合法
// 假设答案是 5，第一个人需要增加 4 点力量值，第二个需要增加 3 点力量值，增加 4 点力量值需要 8 点体力，增加 3 点力量值也需要 8 点体力，8+8>10，不合法

#include <bits/stdc++.h>

using LL = long long;
using ld = long double;
using unl = __int128;
using Pair = std::pair<int, int>;
#define inf 1'000'000'000

void solve(const int &Case) {
    int n, m, k;
    std::cin >> n >> m >> k;
    int V = k * 100; // 考虑所有 b 都是 100，所以是 k * 100
    std::vector<int> a(n), b(m), c(m);
    for (auto &i: a)std::cin >> i;
    for (auto &i: b)std::cin >> i;
    for (auto &i: c)std::cin >> i;
    std::vector<int> f(V + 1, inf);
    f[0] = 0;
    for (int i = 0; i < m; i++) { // 求完全背包
        auto g = f;
        std::vector<int>(V + 1, inf).swap(f);
        for (int j = 0; j <= V; j++) {
            f[j] = g[j];
            if (j >= b[i])f[j] = std::min(f[j], f[j - b[i]] + c[i]);
        }
    }
    // 由于我们想要的是至少，而完全背包求出的是恰好，所以这里要求后缀 min
    for (int i = V - 1; i >= 0; i--)f[i] = std::min(f[i], f[i + 1]);
    // 二分下界其实无所谓，上界要考虑背包的上界，也就是最极限的情况，就是最小值加上所有计划都给最小值
    int l = *std::min_element(a.begin(), a.end()), r = k * 100 + l, ret = l;
    while (l <= r) {
        int mid = (l + r) >> 1;
        LL s = 0;
        for (int i = 0; i < n; i++) {
            int delta = std::max(mid - a[i], 0);
            s += f[delta];
        }
        if (s <= k)l = mid + 1, ret = mid;
        else r = mid - 1;
    }
    std::cout << ret << '\n';
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