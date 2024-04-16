// 基数排序是什么呢？首先默认大家已经会桶排
// a_1 = 105, a_2 = 120, a_3 = 50, a_4 = 17, a_5 = 19
// 如果，我们只看个位数，即 5 0 0 7 9
// 保持原序，A[0] = {a_2, a_3}, A[5] = {a_1}, A[7] = {a_4}, A[9] = {a_5} -> a_2, a_3, a_1, a_4, a_5
// a_2 = 120, a_3 = 50, a_1 = 105, a_4 = 17, a_5 = 19
// 再看十位数，即 a'_2 = 2, a'_3 = 5, a'_1 = 0, a'_4 = 1, a'_5 = 1
// 保持原序，A[0] = {a_1}, A[1] = {a_4, a_5}, A[2] = {a_2}, A[5] = {a_3} -> a_1, a_4, a_5, a_2, a_3
// 再看百位数，即 a'_1 = 1, a'_4 = 0, a'_5 = 0, a'_2 = 1, a'_3 = 0
// 保持原序，A[0] = {a_4, a_5, a_3}, A[1] = {a_1, a_2} -> a_4, a_5, a_3, a_1, a_2
// 时间复杂度 O(n log A)
// 如果每个数的位数都很小，比如只有十位，那这个 log 会比其他排序小不少

#include <bits/stdc++.h>

using LL = long long;
using Pair = std::pair<int, int>;
#define inf 1'000'000'000

void solve(const int &Case) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto &x: a)std::cin >> x;
    int cnt = 0, mx = *std::max_element(a.begin(), a.end());
    while (mx > 0)cnt++, mx /= 10; // 求一共有多少位
    std::array<std::vector<int>, 10> A{};
    for (int T = 0, p = 1; T < cnt; T++, p *= 10) {
        for (const auto &x: a) {
            int c = x / p % 10;
            A[c].push_back(x);
        }
        std::vector<int>().swap(a); // 等价于 a.clear()，但这样能清空空间
        for (int j = 0; j < 10; j++) {
            for (const auto &x: A[j])a.push_back(x);
            std::vector<int>().swap(A[j]);
        }
    }
    for (const auto &x: a)std::cout << x << ' ';
    std::cout << '\n';
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