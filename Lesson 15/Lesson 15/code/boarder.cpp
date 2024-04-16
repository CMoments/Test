// Hash
// abcdab
// a, ab, abc, abcd, abcda, abcdab
// a: 'a'
// ab: 'a' * base + 'b'
// abc: 'a' * base ^ 2 + 'b' * base + 'c'
// bc = abc - a * base ^ 2

#include <bits/stdc++.h>

using LL = long long;
using ld = long double;
using unl = __int128;
using ull = unsigned long long;
using Pair = std::pair<int, int>;
#define inf 1'000'000'000'000'000ll

const ull base = 233;

void solve(const int &Case) {
    std::string s;
    std::cin >> s;
    int n = (int) s.size();
    std::vector<ull> pw(n + 1), has(n + 1);
    pw[0] = 1;
    for (int i = 1; i <= n; i++)pw[i] = pw[i - 1] * base;
    for (int i = 1; i <= n; i++)has[i] = has[i - 1] * base + s[i - 1];
    auto get = [&](int l, int r) {
        return has[r] - has[l] * pw[r - l];
    };
    for (int L = 1; L <= n; L++) {
        if (n % L)continue;
        int fl = 1;
        for (int i = 0; i < n; i += L) {
            if (i + L <= n && get(0, L) != get(i, i + L)) {
                fl = 0;
                break;
            }
        }
        if (fl) {
            std::cout << n / L << '\n';
            return;
        }
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