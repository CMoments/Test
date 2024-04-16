// 选出的两个串，第一个串的一个后缀是 t 的前缀，第二个串的一个前缀是 t 的后缀
// 维护 t 的每一个前缀在 s 中出现的最早位置，每一个后缀在 s 中出现的最迟位置

#include <bits/stdc++.h>

using ull = unsigned long long;
using Pair = std::pair<int, int>;

const ull base = 233;

struct Hash {
    std::vector<ull> pw, has;
    Hash(const std::string &s) {
        int n = (int) s.size();
        pw.resize(n + 1);
        has.resize(n + 1);
        pw[0] = 1;
        for (int i = 1; i <= n; i++)pw[i] = pw[i - 1] * base;
        for (int i = 1; i <= n; i++)has[i] = has[i - 1] * base + s[i - 1];
    }
    ull get(int l, int r) {
        return has[r + 1] - has[l] * pw[r - l + 1];
    }
};

void solve(const int &Case) {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::string s, t;
    std::cin >> s >> t;
    Hash hs(s), ht(t);
    std::vector<int> pl(m, n + 10), pr(m);
    for (int p = k - 1, i = 0; i < std::min(m, k); i++) {
        while (p < n && hs.get(p - i, p) != ht.get(0, i))p++;
        pl[i] = p;
    }
    for (int p = n - k, i = 0; i < std::min(m, k); i++) {
        while (p >= 0 && hs.get(p, p + i) != ht.get(m - i - 1, m - 1))p--;
        pr[m - i - 1] = p;
    }
    for (int i = 0; i < m - 1; i++) {
        if (pl[i] < pr[i + 1]) {
            std::cout << "Yes\n";
            return;
        }
    }
    std::cout << "No\n";
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