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
        for (int x = 0; x < w[i]; x++) { // 按照模意义一下的方式枚举余数
            std::deque<Pair> q; // 双端队列
            for (int j = x, k = 0; j <= V; j += w[i], k++) {
                if (k > 0 && k - q.front().first > s[i])q.pop_front(); // 如果队头已经不在滑动窗口里了，就弹出
                int y = g[j] - k * v[i];
                while (!q.empty() && q.back().second <= y)q.pop_back(); // 如果当前要插入队列的数更优，则弹出队列尾端的数
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