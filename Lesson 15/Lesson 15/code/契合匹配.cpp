// abcd
// bcda
// cdab
// dabc
// abcdabcd

#include <bits/stdc++.h>

using LL = long long;
using ull = unsigned long long;

const ull base = 233;

void solve(const int &Case) {
    int n;
    std::cin >> n;
    std::string s, t;
    std::cin >> s >> t;
    for (int i = 0; i < n; i++) {
        if (t[i] <= 'z' && t[i] >= 'a') {
            t[i] = t[i] - 'a' + 'A';
        }
        else {
            t[i] = t[i] - 'A' + 'a';
        }
    }
    s = s + s;
    n *= 2;
    std::vector<ull> pw(n + 1), has(n + 1);
    pw[0] = 1;
    for (int i = 1; i <= n; i++) {
        pw[i] = pw[i - 1] * base;
    }
    for (int i = 1; i <= n; i++) {
        has[i] = has[i - 1] * base + s[i - 1];
    }
    auto get = [&](int l, int r) {
        return has[r] - has[l] * pw[r - l];
    };
    ull t_hash = 0;
    for (int i = 0; i < n / 2; i++) {
        t_hash = t_hash * base + t[i];
    }
    for (int i = 0; i < n / 2; i++) {
        if (get(i, i + n / 2) == t_hash) {
            std::cout << "Yes\n";
            std::cout << std::min(i, n / 2 - i) << '\n';
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