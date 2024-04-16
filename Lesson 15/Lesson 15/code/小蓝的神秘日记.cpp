// s[2, 4], s[4, 6] 此时这两个串重叠

#include <bits/stdc++.h>

using ull = unsigned long long;
using Pair = std::pair<int, int>;

const ull base = 233;

const int mod = 111;

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
    int l = 1, r = n, ret = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        std::map<ull, int> M;
        // map 记录的是最早出现的那个串的右端点
        int fl = 0;
        for (int i = 0; i + mid - 1 < n; i++) {
            int j = i + mid - 1;
            ull h = get(i, j + 1);
            if (M.count(h)) {
                int p = M[h];
                if (i > p) {
                    fl = 1;
                    break;
                }
            } else M[h] = j;
        }
        if (fl) {
            ret = mid;
            l = mid + 1;
        } else r = mid - 1;
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