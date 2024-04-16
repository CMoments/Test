#include <bits/stdc++.h>

using LL = long long;
using Pair = std::pair<int, int>;
#define inf 1'000'000'000

void solve(const int &Case) {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (auto &x: a)std::cin >> x;
    // 二分模板
    LL l = 0, r = (LL) inf * n, ret = 0;
    while (l <= r) {
        LL mid = (l + r) / 2;
        LL cnt = 0;
        for (const auto &x: a) {
            cnt += std::min((LL) x, mid);
        }
        if (cnt / k >= mid) {
            ret = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    std::cout << ret << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T = 1;
    for (int Case = 1; Case <= T; Case++)solve(Case);
    return 0;
}