#include <bits/stdc++.h>

using LL = long long;
using ull = unsigned long long;
using Pair = std::pair<int, int>;

struct Trie {
    std::vector<std::array<int, 2>> tr;
    std::vector<int> mx;

    Trie() : tr(2, std::array<int, 2>()), mx(2, -1) {}

    int newnode() {
        tr.emplace_back();
        mx.emplace_back(-1);
        return (int) tr.size() - 1;
    }

    void insert(const int &x, const int &p) {
        int u = 1;
        for (int i = 30; i >= 0; i--) {
            int d = x >> i & 1;
            if (!tr[u][d])tr[u][d] = newnode();
            u = tr[u][d];
            mx[u] = std::max(mx[u], p);
        }
    }

    int query(const int &l, const int &x) {
        int u = 1, ret = 0;
        for (int i = 30; i >= 0; i--) {
            int d = x >> i & 1;
            if (mx[tr[u][d ^ 1]] >= l) {
                ret |= 1 << i;
                u = tr[u][d ^ 1];
            }
            else {
                u = tr[u][d];
            }
        }
        return ret;
    }
};

struct Q {
    int l, r, id, p;

    bool operator<(const Q &rhs) const {
        return r < rhs.r;
    }
};

void solve(const int &Case) {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n);
    std::vector<Q> que;
    for (auto &x: a)std::cin >> x;
    for (int i = 0; i < m; i++) {
        char op;
        std::cin >> op;
        if (op == 'A') {
            int x;
            std::cin >> x;
            a.push_back(x);
            n++;
        }
        else {
            int l, r, x;
            std::cin >> l >> r >> x;
            l--, r--;
            que.push_back({l, r, (int) a.size(), x});
        }
    }
    for (int i = n - 2; i >= 0; i--) {
        a[i] ^= a[i + 1];
    }
    int j = 0;
    for (auto &[l, r, id, p]: que) {
        if (id != n)p ^= a[id];
        id = j++;
    }
    std::sort(que.begin(), que.end());
    int i = 0;
    Trie tr;
    std::vector<int> ans(que.size());
    for (int r = 0; r < n; r++) {
        tr.insert(a[r], r);
        while (i < que.size() && que[i].r == r) {
            ans[que[i].id] = tr.query(que[i].l, que[i].p);
            i++;
        }
    }
    for (const auto &x: ans)std::cout << x << '\n';
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