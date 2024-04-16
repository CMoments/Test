// 和最大化卡牌价值那题类似。

#include <bits/stdc++.h>

#include <utility>

using LL = long long;
using ull = unsigned long long;
using ld = long double;
using Pair = std::pair<int, int>;
#define inf 2'000'000'000

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

void solve(const int &Case) {
    int n, m;
    std::cin >> n >> m;
    std::priority_queue<int, std::vector<int>, std::greater<>> q;
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        q.push(x);
    }
    std::vector<Pair> a(m);
    for (auto &[y, x]: a) {
        std::cin >> x >> y;
    }
    std::sort(a.begin(), a.end(), std::greater<>());
    for (auto [y, x]: a) {
        while (x--) {
            if (q.top() >= y) {
                LL ans = 0;
                while (!q.empty()) {
                    ans += q.top();
                    q.pop();
                }
                std::cout << ans << '\n';
                return;
            }
            q.pop();
            q.push(y);
        }
    }
    LL ans = 0;
    while (!q.empty()) {
        ans += q.top();
        q.pop();
    }
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