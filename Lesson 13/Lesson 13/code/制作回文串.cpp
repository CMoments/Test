// 回文串的一个特性是，去掉两个端点后还是回文串

#include <bits/stdc++.h>

using LL = long long;
using ld = long double;
using Pair = std::pair<int, int>;
#define inf 1'000'000'000

void solve(const int &Case) {
    int n, m;
    std::cin >> n >> m;
    std::string s;
    std::cin >> s;
    std::vector<int> a(26);
    for (int i = 0; i < n; i++) {
        char ch;
        std::cin >> ch;
        int x, y;
        std::cin >> x >> y;
        a[ch - 'a'] = std::min(x, y);
    }
    std::vector<std::vector<int>> f(m, std::vector<int>(m));
    for (int len = 1; len < m; len++) {
        for (int l = 0, r = len; r < m; l++, r++) {
            if (s[l] == s[r])f[l][r] = f[l + 1][r - 1];
            else f[l][r] = std::min(f[l + 1][r] + a[s[l] - 'a'], f[l][r - 1] + a[s[r] - 'a']);
        }
    }
    std::cout << f[0][m - 1] << '\n';
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