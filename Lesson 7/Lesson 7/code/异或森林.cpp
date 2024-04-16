#include <bits/stdc++.h>

using LL = long long;
using Pair = std::pair<int, int>;
#define inf 1'000'000'000

void solve(const int &Case) {
    int n;
    std::cin >> n;
    std::vector<int> a(n), sum_xor(n + 1);
    for (auto &x: a)std::cin >> x;
    for (int i = 1; i <= n; i++)sum_xor[i] = sum_xor[i - 1] ^ a[i - 1];
    int ans = n * (n + 1) / 2;
    std::vector<int> cnt(4 * n + 1);
    // cnt_i 存 S_l = i 的个数
    cnt[0] = 1;
    for (int r = 1; r <= n; r++) {
        for (int i = 0; i * i <= 2 * n; i++) {
            ans -= cnt[sum_xor[r] ^ (i * i)];
        }
        cnt[sum_xor[r]]++;
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