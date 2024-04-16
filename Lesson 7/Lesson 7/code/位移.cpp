#include <bits/stdc++.h>

using LL = long long;
using Pair = std::pair<int, int>;
#define inf 1'000'000'000

void solve(const int &Case) {
    int a, b;
    std::cin >> a >> b;
    if (b == 0) {
        std::cout << "Yes\n";
        return;
    }
    while (a % 2 == 0)a >>= 1;
    while (b % 2 == 0)b >>= 1;
    if (a < b) {
        std::cout << "No\n";
        return;
    }
    std::vector<int> A, B;
    while (a > 0) {
        A.push_back(a & 1);
        a >>= 1;
    }
    while (b > 0) {
        B.push_back(b & 1);
        b >>= 1;
    }
    int n = (int) A.size(), m = (int) B.size();
    for (int i = 0; i + m - 1 < n; i++) {
        int fl = 0;
        for (int j = 0; j < m; j++) {
            if (A[i + j] != B[j]) {
                fl = 1;
                break;
            }
        }
        if (!fl) {
            std::cout << "Yes\n";
            return;
        }
    }
    std::cout << "No\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T = 1;
    std::cin >> T;
    for (int Case = 1; Case <= T; Case++)solve(Case);
    return 0;
}