#include <bits/stdc++.h>

using LL = long long;
using Pair = std::pair<int, int>;
#define inf 1'000'000'000

void solve(const int &Case) {
    int n, l, r, x;
    std::cin >> n >> l >> r >> x;
    std::vector<int> a(n);
    for (auto &i: a)std::cin >> i;
    int ans = 0;
    for (int S = 0; S < (1 << n); S++) {
        int sum = 0, mx = 0, mn = inf;
        std::vector<int> A;
        for (int i = 0; i < n; i++) {
            if (S >> i & 1) {
                sum += a[i];
                mx = std::max(mx, a[i]);
                mn = std::min(mn, a[i]);
                A.push_back(a[i]);
            }
        }
        std::sort(A.begin(), A.end());
        A.erase(std::unique(A.begin(), A.end()), A.end());
        if (sum >= l && sum <= r && mx - mn >= x && A.size() >= 3)ans++;
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