// 我们有一个想法，设 f[S] 表示达到 S 所需的最小代价和
// 如果 S 的第 i 位是 0, 则说明可以从 S ^ (1 << i) 把第 i 位关灯转移到 S
// 如果 S 的第 i 位是 1, 则说明可以从 S ^ (1 << i) 把第 i 位开灯转移到 S
// 还有种可能是从交换第 i 位和第 j 位转移过来的, 即
// 设 c = S >> i & 1, d = S >> j & 1, 那么就是从 S ^ (c << j) ^ (d << i) ^ (c << i) ^ (d << j) 转移得到
// 问题是我们好像根本不知道合理的转移顺序
// 其实存在某种贪心性质的转移顺序，被称为 Dijkstra，感兴趣可以提前学习

#include <bits/stdc++.h>

using LL = long long;
using ld = long double;
using Pair = std::pair<LL, int>;
#define inf 1'000'000'000'000'000'000ll

void solve(const int &Case) {
    int n, z;
    std::cin >> n >> z;
    std::vector<int> x(n), y(n);
    int st = 0, ed = 0;
    for (auto &t: x)std::cin >> t;
    for (auto &t: y)std::cin >> t;
    for (int i = 0; i < n; i++) {
        int t;
        std::cin >> t;
        st |= t << i;
    }
    for (int i = 0; i < n; i++) {
        int t;
        std::cin >> t;
        ed |= t << i;
    }
    std::vector<LL> f(1 << n, inf);
    std::vector<int> vis(1 << n);
    f[st] = 0;
    std::priority_queue<Pair, std::vector<Pair>, std::greater<>> q;
    q.emplace(0, st);
    while (!q.empty()) {
        auto [D, u] = q.top();
        q.pop();
        if (vis[u])continue;
        vis[u] = 1;
        for (int i = 0; i < n; i++) {
            int v = u ^ (1 << i);
            if (u >> i & 1) {
                if (f[v] > f[u] + y[i]) {
                    f[v] = f[u] + y[i];
                    q.emplace(f[v], v);
                }
            } else {
                if (f[v] > f[u] + x[i]) {
                    f[v] = f[u] + x[i];
                    q.emplace(f[v], v);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int c = u >> i & 1;
                int d = u >> j & 1;
                int v = u ^ (c << j) ^ (d << i) ^ (c << i) ^ (d << j);
                if (f[v] > f[u] + z) {
                    f[v] = f[u] + z;
                    q.emplace(f[v], v);
                }
            }
        }
    }
    std::cout << f[ed] << '\n';
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