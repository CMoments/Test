#include <bits/stdc++.h>

using LL = long long;
using ld = long double;
using Pair = std::pair<int, int>;
#define inf 1'000'000'000

struct BIT {
    std::vector<int> tr;
    int n;

    BIT(int n) : n(n), tr(n + 1) {}

    int lowbit(const int &x) {
        return x & (-x);
    }

    void modify(const int &x, const int &y) {
        for (int i = x; i <= n; i += lowbit(i)) {
            tr[i] = std::max(tr[i], y);
        }
    }

    int query(const int &x) {
        int ret = 0;
        for (int i = x; i > 0; i -= lowbit(i)) {
            ret = std::max(ret, tr[i]);
        }
        return ret;
    }
};

void solve(const int &Case) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto &i: a)std::cin >> i;
    auto o = a;
    std::sort(o.begin(), o.end());
    o.erase(std::unique(o.begin(), o.end()), o.end());
    for (auto &i: a)i = (int) (std::lower_bound(o.begin(), o.end(), i) - o.begin() + 1);
    int m = (int) o.size();
    BIT T(m);
    for (const auto &x: a) {
        int f = T.query(x - 1);
        T.modify(x, f + 1);
    }
    std::cout << T.query(m) << '\n';
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