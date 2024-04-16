// 可以尝试写一份倍增的代码试一下
// hint: F_{x, i} 表示从 x 开始走 2 ^ i 步停在哪

#include <bits/stdc++.h>

using LL = long long;
using Pair = std::pair<int, int>;
#define inf 1'000'000'000

void solve(const int &Case) {
    int n;
    std::cin >> n;
    LL k;
    std::cin >> k;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)std::cin >> a[i];
    std::vector<int> f(n + 1);
    int now = 1;
    auto jump = [&](int x, int p) {
        for (int i = 0; i < p; i++)x = a[x];
        return x;
    };
    for (int i = 1;; i++, k--) {
        if (f[now] != 0) {
            int len = i - f[now];
            int p = (int) (k % len);
            std::cout << jump(now, p) << '\n';
            return;
        } else {
            f[now] = i;
            now = a[now];
        }
        if (i == k) {
            std::cout << now << '\n';
            return;
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T = 1;
    for (int Case = 1; Case <= T; Case++)solve(Case);
    return 0;
}