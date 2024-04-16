#include <bits/stdc++.h>

using LL = long long;
using ld = long double;
using Pair = std::pair<int, int>;
#define inf 1'000'000'000

void solve(const int &Case) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto &i:a)std::cin >> i;
    std::vector<int> f(n), g(n + 1, inf + 1);
    g[0] = 0;
    int L = 0;
    for (int i = 0; i < n; i++) {
        int l = 0, r = L, ret = 0;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (g[mid] < a[i]) {
                ret = mid;
                l = mid + 1;
            } else r = mid - 1;
        }
        f[i] = ret + 1;
        g[f[i]] = std::min(g[f[i]], a[i]);
        if (ret == L)L++;
    }
    std::cout << L << '\n';
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