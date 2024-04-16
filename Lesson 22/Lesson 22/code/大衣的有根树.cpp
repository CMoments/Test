#include <bits/stdc++.h>

#include <utility>

using LL = long long;
using ull = unsigned long long;
using ld = long double;
using Pair = std::pair<int, int>;
#define inf 2'000'000'000

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

void solve(const int &Case) {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> G(n + 1);
    for (int i = 2; i <= n; i++) {
        int f;
        std::cin >> f;
        G[f].push_back(i);
    }
    std::vector<int> a(n);
    for (int i = 0; i < n; i++)std::cin >> a[i];
    auto o = a;
    std::sort(o.begin(), o.end());
    o.erase(std::unique(o.begin(), o.end()), o.end());
    for (int i = 0; i < n; i++)a[i] = (int) (std::lower_bound(o.begin(), o.end(), a[i]) - o.begin());
    std::vector<std::vector<int>> A(o.size());
    LL ans = 0;
    std::function<void(int, int, int)> dfs = [&](int x, int las, int depx) {
        if (!A[a[x - 1]].empty()) {
            las = std::max(las, A[a[x - 1]].back());
        }
        A[a[x - 1]].push_back(depx);
        ans += depx - las;
        for (const auto &tox: G[x]) {
            dfs(tox, las, depx + 1);
        }
        A[a[x - 1]].pop_back();
    };
    dfs(1, 0, 1);
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