#include <bits/stdc++.h>

using LL = long long;
using Pair = std::pair<int, int>;
#define inf 1'000'000'000

void solve(const int &Case) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    int m;
    std::cin >> m;
    std::vector<int> H(m);
    for (auto &x: H)std::cin >> x;
    for (auto &x: a)std::cin >> x;
    int sw = 0, com = 0;
    for (const auto &h: H) {
        for (int i = h; i < n; i++) {
            for (int j = i; j >= h; j -= h) {
                com++;
                if (a[j] < a[j - h])std::swap(a[j], a[j - h]), sw++;
                else break;
            }
        }
    }
    std::cout << com << ' ' << sw << '\n';
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