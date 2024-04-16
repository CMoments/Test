// 若确定了第一组的最大值和第二组的最小值，剩下来的数，若小于第一组的塞第一组即可，否则塞第二组
// 如果不合法，即第一组最大值小于第二组最小值，无意义，因为你交换第一组最大值和第二组最小值，答案不变
// 等价于第一组选择任意一个数，第二组也选择任意一个数，只要这两个数不是第一个数，都是合法的
// 等价于选择任意两个数，差值的绝对值最小
// 排序后取相邻之差的最小值

#include <bits/stdc++.h>

using LL = long long;
using Pair = std::pair<int, int>;
#define inf 1'000'000'000

void solve(const int &Case) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto &x: a)std::cin >> x;
    int ans = inf;
    std::sort(a.begin(), a.end());
    for (int i = 0; i < n - 1; i++) { // 不要越界
        ans = std::min(ans, a[i + 1] - a[i]);
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