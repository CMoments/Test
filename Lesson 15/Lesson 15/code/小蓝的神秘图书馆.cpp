#include <bits/stdc++.h>

using LL = long long;
using ull = unsigned long long;
using Pair = std::pair<int, int>;

struct Trie {
    std::vector<std::array<int, 26>> tr;
    std::vector<int> sz;

    Trie(): tr(2, std::array<int, 26>()), sz(2) {}

    int newnode() {
        tr.emplace_back();
        sz.emplace_back();
        return (int) tr.size() - 1;
    }

    void insert(const std::string &s) {
        int u = 1;
        for (const auto &c: s) {
            int d = c - 'a';
            if (!tr[u][d])tr[u][d] = newnode();
            u = tr[u][d];
            sz[u]++;
        }
    }

    int query(const std::string &s) {
        int u = 1;
        for (const auto &c: s) {
            int d = c - 'a';
            u = tr[u][d];
        }
        return sz[u];
    }
};

void solve(const int &Case) {
    int n, m;
    std::cin >> n >> m;
    Trie tr;
    for (int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;
        tr.insert(s);
    }
    while (m--) {
        std::string t;
        std::cin >> t;
        std::cout << tr.query(t) << '\n';
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