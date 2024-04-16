// 插入排序: if a_i > a_{i + 1} then swap(a_i, a_{i + 1}) else break
// 等价于每一次将第一个数塞到合适的位置
// 冒泡排序: if a_i > a_{i + 1} then swap(a_i, a_{i + 1})
// 等价于每一次将最大的数塞到最后面
// 希尔排序: if a_i > a_{i + h} then swap(a_i, a_{i + h}) else break 
// h = n / 2, n / 4, ..., 1
// 等价于分组将最前面的数塞到合适位置

#include <bits/stdc++.h>

using LL = long long;
using Pair = std::pair<int, int>;
#define inf 1'000'000'000

void solve(const int &Case) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto &x: a)std::cin >> x;
    int h = n / 2;
    while (h >= 1) {
        for (int i = h; i < n; i++) {
            for (int j = i; j >= h && a[j] < a[j - h]; j -= h) {
                std::swap(a[j], a[j - h]);
            }
        }
        h = h / 2;
    }
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " \n"[i == n - 1];
    }
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