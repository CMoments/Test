#include <bits/stdc++.h>

using LL = long long;
using ld = long double;
using Pair = std::pair<ld, ld>;
#define inf 1'000'000'000

struct Q {
    int op, x, y;
};

void solve(const int &Case) {
    int n;
    std::cin >> n;
    std::string s, t;
    std::cin >> s >> t;
    int k;
    std::cin >> k;
    std::vector<Q> que(k);
    for (auto &[op, x, y]: que)std::cin >> op >> x >> y;
    for (int S = 0; S < 1 << k; S++) { // 枚举子集，忘了的可以看之前位运算时的课
        std::vector<int> tmp;
        for (int i = 0; i < k; i++) {
            if (S >> i & 1)tmp.push_back(i);
        }
        do {
            std::string now = s;
            for (auto i: tmp) {
                const auto &[op, x, y] = que[i];
                if (op == 1) {
                    s[x] = char('0' + (s[x] - '0' + y) % 10);
                } else {
                    std::swap(s[x], s[y]);
                }
            }
            if (now == t) {
                std::cout << "Yes\n";
                return;
            }
        } while (std::next_permutation(tmp.begin(), tmp.end())); // 枚举排列，得到任意顺序
    }
    std::cout << "No\n";
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