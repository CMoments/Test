#include <bits/stdc++.h>

using LL = long long;
using ull = unsigned long long;
using Pair = std::pair<int, int>;

const ull base = 233;

struct Hash {
    std::string s;
    int n;
    std::vector<ull> pw, h;

    Hash(std::string s) : s(s), n((int) s.size()), pw(n + 1), h(n + 1) {
        pw[0] = 1;
        for (int i = 1; i <= n; i++)pw[i] = pw[i - 1] * base;
        for (int i = 1; i <= n; i++)h[i] = h[i - 1] * base + s[i - 1];
    }

    ull get(int l, int r) {
        return h[r + 1] - h[l] * pw[r - l + 1];
    }
};

void solve(const int &Case) {
    std::string s;
    std::cin >> s;
    int n = (int) s.size();
    Hash A(s);
    std::reverse(s.begin(), s.end());
    Hash B(s);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int l = 1, r = std::min(i + 1, n - i), ret = 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (A.get(i - mid + 1, i) == B.get(n - i - mid, n - 1 - i)) {
                ret = mid;
                l = mid + 1;
            } else r = mid - 1;
        }
        ans = std::max(ans, ret * 2 - 1);
        l = 1, r = std::min(i + 1, n - i - 1), ret = 0;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (A.get(i - mid + 1, i) == B.get(n - 1 - i - mid, n - 1 - i - 1)) {
                ret = mid;
                l = mid + 1;
            } else r = mid - 1;
        }
        ans = std::max(ans, ret * 2);
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