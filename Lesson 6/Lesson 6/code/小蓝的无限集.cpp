// 如果第一次执行乘 a，一定会是 a ^ i + kb
// 如果第一次执行加 b，一定会是 (pb + 1)a ^ i + kb = a ^ i + b (pa^i + k)
// 最终一定是 a ^ i + kb

#include <bits/stdc++.h>

using LL = long long;
using Pair = std::pair<int, int>;
#define inf 1'000'000'000

void solve(const int &Case) {
    int a, b, n;
    std::cin >> a >> b >> n;
    if (a == 1) {
        if (n % b == 1)std::cout << "Yes\n";
        else std::cout << "No\n";
        return;
    }
    // 枚举 a ^ i
    LL pw = 1;
    while (pw <= n) {
        if ((n - pw) % b == 0) {
            std::cout << "Yes\n";
            return;
        }
        pw *= a;
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