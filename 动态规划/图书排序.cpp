#include <bits/stdc++.h>

using LL = long long;
using Pair = std::pair<int, int>; // pair<T, T> 和 pair<T, T> 是可以直接比较的
// A = (x, y) 是 pair 类型
// B = (a, b) 是 pair 类型
// A < B iff (x < a) || (x == a && y < b)
#define inf 1'000'000'000

void solve(const int &Case) {
    int n;
    std::cin >> n;
    std::vector<Pair> a(n);
    for (auto &[x, y]: a)std::cin >> y >> x;
    int h = n / 2;
    while (h >= 1) {
        for (int i = h; i < n; i++) {
            for (int j = i; j >= h && a[j] < a[j - h]; j -= h) {
                std::swap(a[j], a[j - h]);
            }
        }
        h = h / 2;
    }
    for (int i = 0; i < n; i++) {
        std::cout << a[i].second << '\n';
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