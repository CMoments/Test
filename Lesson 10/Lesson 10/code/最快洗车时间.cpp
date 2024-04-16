// 3
// 1 2 3
// f[0][0] = true
// f[1][0] = true f[1][1] = true
// f[2][0] = true f[2][1] = true f[2][2] = true f[2][3] = true
// f[3][0] = true f[3][1] = true f[3][2] = true f[3][3] = true f[3][4] = true f[3][5] = true f[3][6] = true


#include <bits/stdc++.h>

using LL = long long;
using ld = long double;
using Pair = std::pair<ld, ld>;
#define inf 1'000'000'000

void solve(const int &Case) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    int s = 0;
    for (auto &i: a)std::cin >> i, s += i;
    std::vector<int> f(s + 1);
    f[0] = 1;
    for (auto i: a) {
        auto g = f;
        std::vector<int>(s + 1).swap(f);
        for (int j = 0; j <= s; j++) {
            f[j] = g[j];
            if (j - i >= 0)f[j] |= g[j - i];
        }
    }
    int ans = inf;
    for (int i = 0; i <= s; i++) {
        if (f[i])ans = std::min(ans, std::max(i, s - i));
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