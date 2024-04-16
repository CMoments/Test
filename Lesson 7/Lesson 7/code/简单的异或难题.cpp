#include <bits/stdc++.h>

using LL = long long;
using Pair = std::pair<int, int>;
#define inf 1'000'000'000

void solve(const int &Case) {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n), sum_xor(n + 1);
    for (auto &i: a)std::cin >> i;
    for (int i = 1; i <= n; i++)sum_xor[i] = sum_xor[i - 1] ^ a[i - 1];
    while (m--) {
        int l, r;
        std::cin >> l >> r;
        std::cout << (sum_xor[r] ^ sum_xor[l - 1]) << '\n';
    }
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