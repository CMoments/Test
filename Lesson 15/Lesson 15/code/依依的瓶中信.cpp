#include <bits/stdc++.h>

using ull = unsigned long long;
using Pair = std::pair<int, int>;

struct Trie {
    std::vector<std::array<int, 26>> tr;
    int cnt;
    Trie() : tr(2, {0, 0}), cnt(1) {}

    void init() {
        tr.clear();
        tr.resize(2, {0, 0});
        cnt = 1;
    }

    int newnode() {
        tr.emplace_back();
        return ++cnt;
    }

    int insert(const std::string &s) {
        int u = 1, t = 0;
        for (char c : s) {
            int d = c - 'a';
            if (!tr[u][d]) tr[u][d] = newnode();
            else t++;
            u = tr[u][d];
        }
        return t;
    }
};

void solve(const int &Case) {
    int n;
    std::cin >> n;
    std::vector<std::string> a(n);
    std::vector<int> mx(n);
    Trie trie;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        mx[i] = trie.insert(a[i]);
    }
    trie.init();
    for (int i = n - 1; i >= 0; i--) {
        mx[i] = std::max(mx[i], trie.insert(a[i]));
    }
    for (int i = 0; i < n; i++) {
        std::cout << mx[i] << '\n';
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