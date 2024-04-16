#include <bits/stdc++.h>

using LL = long long;
using Pair = std::pair<int, int>;

void solve(const int &Case) {
    int l, r;
    std::cin >> l >> r;
    std::vector<int> prim, vis(r + 1), phi(r + 1);
    phi[1] = 1;
    for (int i = 2; i <= r; i++) {
        if (!vis[i]) {
            prim.push_back(i);
            phi[i] = i - 1;
        }
        for (int j = 0, sz = (int) prim.size(); j < sz && i * prim[j] <= r; j++) {
            vis[i * prim[j]] = 1;
            if (i % prim[j] == 0) {
                phi[i * prim[j]] = phi[i] * prim[j];
                break;
            } else {
                phi[i * prim[j]] = phi[i] * (prim[j] - 1);
            }
        }
    }
    LL ans = 0;
    for (int i = l; i <= r; i++) {
        ans += phi[i];
    }
    std::cout << ans << '\n';
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