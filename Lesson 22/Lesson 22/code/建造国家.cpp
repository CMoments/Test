#include <bits/stdc++.h>

#include <utility>

using LL = long long;
using ull = unsigned long long;
using ld = long double;
using Pair = std::pair<int, int>;
#define inf 2'000'000'000

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

void solve(const int &Case) {
    int n, k;
    std::cin >> n >> k;
    std::cout << k - 1 << '\n';
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