// 等价于对于任意两个距离小于等于 D 的人都连一条边
// 求起点所在连通块的大小


#include <bits/stdc++.h>

using LL = long long;
using ld = long double;
using Pair = std::pair<ld, ld>;
#define inf 1'000'000'000

void solve(const int &Case) {
    int n;
    std::cin >> n;
    std::vector<Pair> a(n);
    for (auto &[x, y]: a)std::cin >> x >> y;
    int D;
    std::cin >> D;
    std::vector<int> vis(n);
    auto norm = [&](const auto &x, const auto &y) { // 距离的平方
        return (x.first - y.first) * (x.first - y.first) + (x.second - y.second) * (x.second - y.second);
    };
    auto dfs = [&](int x) {
        vis[x] = 1; // 标记当前人已经搜索过，以后不用再搜索
        for (int i = 0; i < n; i++) {
            if (vis[i])continue; // 如果下一个人已经被搜索过，则不会再去搜
            if (norm(a[i], a[x]) <= D * D)dfs(i);
        }
    };
    dfs(0);
    for (const auto &x: vis)std::cout << x << '\n';
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
