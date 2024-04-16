// 和上一题是类似的，把 A -> A / B + C 看成一条边即可，A 和 A / B + C 都是节点

#include <bits/stdc++.h>

using LL = long long;
using Pair = std::pair<int, int>;
#define inf 1'000'000'000

void solve(const int &Case) {
    int A, B, C, Q;
    std::cin >> A >> B >> C >> Q;
    if (B == 1) {
        std::cout << A + (LL) C * Q << '\n';
        return;
    }
    LL ans = 0;
    std::vector<std::array<int, 31>> F(2'000'01);
    for (int i = 0; i <= 2'000'00; i++) {
        F[i][0] = i / B + C;
    }
    // 倍增时一定是先枚举 j
    for (int j = 1; j <= 30; j++) {
        for (int i = 0; i <= 2'000'00; i++) {
            // 防止数组越界
            if (F[i][j - 1] > 2'000'00)F[i][j] = inf;
            else F[i][j] = F[F[i][j - 1]][j - 1];
        }
    }
    ans = A;
    for (int i = 30; i >= 0; i--) {
        if (Q >> i & 1)ans = F[ans][i];
    }
    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T = 1;
    for (int Case = 1; Case <= T; Case++)solve(Case);
    return 0;
}