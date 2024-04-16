// 先判断无解
// 发现 2, 3 可以构造所有，知道了答案上界
// 只需考虑答案为 0 时是怎么样
// 此时所有 P, Q 内元素都相同，不妨假设为 p
// A = np, B = mp
// p | gcd(A, B)
// 而一个大于 1 的数 x 而言，一定只有自己的质因子

#include <bits/stdc++.h>

using LL = long long;
using Pair = std::pair<int, int>;
#define inf 1'000'000'000

void solve(const int &Case) {
    LL A, B;
    std::cin >> A >> B;
    if (A == 1 || B == 1) {
        std::cout << "-1\n";
        return;
    }
    LL gcd = std::gcd(A, B);
    if (gcd == 1) {
        std::cout << "1\n";
    }
    else {
        std::cout << "0\n";
    }
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