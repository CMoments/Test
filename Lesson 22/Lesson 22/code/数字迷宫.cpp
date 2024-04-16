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
    std::vector<int> A;
    auto ck = [&](int x) {
        while (x > 0) {
            int c = x % 10;
            if (c == 2 || c == 4)return false;
            x /= 10;
        }
        return true;
    };
    std::vector<int> valid(n + 1);
    for (int i = 1; i <= n; i++) {
        if (ck(i))A.push_back(i), valid[i] = 1;
    }
    // std::cout << std::accumulate(valid.begin(), valid.end(), 0) << '\n';
    int ans = 0;
    for (int i = 0, sz = (int) A.size(); i < sz; i++) {
        for (int j = i + 1; j < sz; j++) {
            int x = A[i], y = A[j], z = n - x - y;
            if (z < 0 || !valid[z] || z <= y)continue;
            ans++;
        }
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