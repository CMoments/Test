#include <bits/stdc++.h>

using LL = long long;
using Pair = std::pair<int, int>;
#define inf 1'000'000'000

void solve(const int &Case) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto &i:a)std::cin >> i;
    int now = 0;
    // vis_i 表示 i 这个数是否已经被选择了
    std::vector<int> vis(n);
    for (int i = 0; i < n; i++) { // 循环次数不超过 log A
        int id = -1;
        for (int j = 0; j < n; j++) {
            if (vis[j])continue;
            if (id == -1 || (a[j] | now) > (a[id] | now))id = j;
        }
        std::cout << a[id] << ' ';
        vis[id] = 1;
        if ((a[id] | now) == now)break;
        now |= a[id];
    }
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            std::cout << a[i] << ' ';
        }
    }
    std::cout << '\n';
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