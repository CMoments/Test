#include <bits/stdc++.h>

using LL = long long;
using ld = long double;
using unl = __int128;
using Pair = std::pair<int, int>;
#define inf 1'000'000'000

void solve(const int &Case) {
    int n, V;
    std::cin >> n >> V;
    std::vector<int> v(n), w(n), s(n);
    for (int i = 0; i < n; i++)std::cin >> w[i] >> v[i] >> s[i];
    std::vector<int> f(V + 1, -inf);
    f[0] = 0;
    for (int i = 0; i < n; i++) {
        auto g = f;
        std::vector<int>(V + 1, -inf).swap(f);
        for (int x = 0; x < w[i]; x++) {
            std::deque<Pair> q;
            for (int j = x, k = 0; j <= V; j += w[i], k++) {
                if (k > 0 && k - q.front().first > s[i])q.pop_front();
                int y = g[j] - k * v[i];
                while (!q.empty() && q.back().second <= y)q.pop_back();
                q.emplace_back(k, y);
                f[j] = q.front().second + k * v[i];
            }
        }
    }
    std::cout << *std::max_element(f.begin(), f.end()) << '\n';
}

int main() {
//    freopen("1.in", "r", stdin);
//    freopen("2.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T = 1;
//    std::cin >> T;
    for (int Case = 1; Case <= T; Case++)solve(Case);
    return 0;
}