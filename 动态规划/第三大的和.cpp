// 5
// 1 2 3 4 5
// 1 + 2 + 3 = 6, 1 + 2 + 4 = 7, 1 + 2 + 5 = 8
// 1 + 3 + 4 = 8, 1 + 3 + 5 = 9, 1 + 4 + 5 = 10
// 2 + 3 + 4 = 9, 2 + 3 + 5 = 10, 2 + 4 + 5 = 11
// 3 + 4 + 5 = 12
// 6, 7, 8, 8, 9, 9, 10, 10, 11, 12


// 关于多数和的最大/次大/第三大/第 k 大
// 三个数和的最大
// 对原序列从大到小排序，假设是 a_1, a_2, ..., a_n
// 最大的和一定是 a_1 + a_2 + a_3
// 次大的和一定是 a_1 + a_2 + a_4
// 第三大的和可能是 a_1 + a_3 + a_4, a_1 + a_2 + a_5
// 再接下来可能的拓展 a_2 + a_3 + a_4, a_1 + a_3 + a_5, a_1 + a_3 + a_5, a_1 + a_2 + a_6

#include <bits/stdc++.h>

using LL = long long;
using Pair = std::pair<int, int>;
#define inf 1'000'000'000

void solve(const int &Case) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto &i: a)std::cin >> i;
    std::sort(a.begin(), a.end(), std::greater<>());
// 由于相同的和只能保留一个
// 此时对于任意一种数而言，它最多是出现三次有用
    std::vector<int> b;
    for (int i = 0; i < n;) {
        int j = i;
        while (j < n && a[j] == a[i])j++;
        int l = j - i;
        l = std::min(l, 3);
        while (l--)b.push_back(a[i]);
        i = j;
    }
    a = b;
    n = std::min((int) a.size(), 6);
    std::vector<int>().swap(b);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                b.push_back(a[i] + a[j] + a[k]);
            }
        }
    }
    std::sort(b.begin(), b.end(), std::greater<>());
    b.erase(std::unique(b.begin(), b.end()), b.end());
    std::cout << b[2] << '\n';
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