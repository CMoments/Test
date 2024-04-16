#include <bits/stdc++.h>

using LL = long long;
using ld = long double;
using Pair = std::pair<ld, ld>;
#define inf 1'000'000'000

void solve(const int &Case) {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)std::cin >> a[i];
    std::vector<int> ls(n + 1), rs(n + 1); // 二叉树专属写法
    // std::vector<std::vector<int>> G(n + 1); // 任意图写法
    for (int i = 1; i <= n; i++) {
        std::cin >> ls[i] >> rs[i];
    }
    int ans = 0;
    std::function<void(int, int)> dfs = [&](int x, int w) {
        if (x == -1)return;
        if (w == 0)ans += a[x];
        dfs(ls[x], w + 1);
        dfs(rs[x], w - 1);
    };
    dfs(1, 0);
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