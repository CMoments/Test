// border: p (p < n) 是字符串 s 的一个 border 则意味着 s[1, p] = s[n - p + 1, n], n 为 s 的长度
// kmp: 求字符串 s 的每一个前缀的最长 border, 我们称之为 nxt
// 性质: border 的 border 是 border
// abababab
// border 有 ababab, abab, ab
// 注意到 ababab 的 border 有 abab, ab
// 证明: 假设 p 是 s 的一个 border, q 是 s[1, p] 的一个 border
// 则有 s[1, p] = s[n - p + 1, n], s[1, q] = s[p - q + 1, p] = s[n - q + 1, n]
// 于是 q 也是 s 的一个 border
// 该性质保证了 border 之间存在树的关系, 我们称之为 border 树
// kmp 实际上就是在求 border 树, 即树上的边为 (nxt[i], i)
// 这道题实际上在求 border 树的深度之和, 也就是子🌲大小之和

#include <bits/stdc++.h>

using LL = long long;

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
};

void solve(const int &Case) {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    KMP kmp(s);
    std::vector<LL> dp(n, 1);
    for (int i = n - 1; i >= 0; i--) {
        if (kmp.nxt[i] != -1)dp[kmp.nxt[i]] += dp[i];
    }
    std::cout << std::accumulate(dp.begin(), dp.end(), 0ll) << '\n';
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