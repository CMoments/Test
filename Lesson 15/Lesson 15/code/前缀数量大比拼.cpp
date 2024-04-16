#include <bits/stdc++.h>

using LL = long long;
using ull = unsigned long long;

struct KMP {
    std::string s;
    std::vector<int> nxt;
    int n;

    KMP(const std::string &A) {
        n = (int) A.size();
        s = A, nxt.resize(n);
        nxt[0] = -1;
        for (int i = 1; i < n; i++) {
            int j = nxt[i - 1];
            while (s[j + 1] != s[i] && j >= 0)j = nxt[j];
            if (s[j + 1] == s[i])nxt[i] = j + 1;
            else nxt[i] = -1;
        }
    }

    LL solve(const std::string &t) {
        int m = (int) t.size();
        std::vector<LL> f(n);
        for (int i = 0, j = -1; i < m; i++) {
            while (s[j + 1] != t[i] && j >= 0)j = nxt[j];
            if (s[j + 1] == t[i])j++;
            if (j >= 0)f[j]++;
            if (j == n - 1)j = nxt[j];
        }
        for (int i = n - 1; i >= 0; i--) {
            if (nxt[i] != -1)f[nxt[i]] += f[i];
        }
        return std::accumulate(f.begin(), f.end(), 0LL);
    }
};

void solve(const int &Case) {
    int n;
    std::cin >> n;
    std::string s, t;
    std::cin >> s >> t;
    KMP S(s), T(t);
    LL at = S.solve(t), as = T.solve(s);
    if (as > at)std::cout << "Xiaoqiu\n";
    else if (as < at)std::cout << "Xiaoyu\n";
    else std::cout << "Draw\n";
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