#include <bits/stdc++.h>

using LL = long long;
using ld = long double;
using unl = __int128;
using ull = unsigned long long;
using Pair = std::pair<int, int>;
#define inf 1'000'000'000'000'000ll

const ull base = 233;

void solve(const int &Case) {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::vector<ull> pw(n + 1), has(n + 1);
    pw[0] = 1;
    for (int i = 1; i <= n; i++)pw[i] = pw[i - 1] * base;
    for (int i = 1; i <= n; i++)has[i] = has[i - 1] * base + s[i - 1];
    auto get = [&](int l, int r) {
        return has[r] - has[l] * pw[r - l];
    };
    int l = 0, r = n - 1, ret = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        int fl = 0;
        for (int i = 1; i < n; i++) {
            if (i + mid > n)break;
            if (get(0, mid) == get(i, i + mid)) {
                fl = 1;
                break;
            }
        }
        if (fl)ret = mid, l = mid + 1;
        else r = mid - 1;
    }
    std::cout << ret << '\n';
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