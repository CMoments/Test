// 注意到一个极其重要的事情，若一个位置可以被分割，则它永远可以被分割，且代价不变 (key observation)
// 6
// 1 2 3 4 5 6
//  1 2 3 4 5
// 位置 2, 4 可以分割
// 如果把奇数看成 1，偶数看成 -1（这个思路在括号序列中很常见），可分割等价于分割的左部和为 0，右部和也为 0，于是总的和也为 0
// 而每次分割等价于把 0 拆成两个 0，所以可分割的永远可分割
// 同时分割的两边的数不变，所以分割代价不变
// 又要分割次数足够多
// 所以直接选择分割代价最小的来进行分割
// 求出所有可分割的位置和代价，排序，从小到大选择即可

#include <bits/stdc++.h>

using LL = long long;
using Pair = std::pair<int, int>;
#define inf 1'000'000'000

void solve(const int &Case) {
    int n, B;
    std::cin >> n >> B;
    std::vector<int> a(n);
    int odd = 0, even = 0;
    // odd 是奇数个数，even 是偶数个数
    for (auto &x: a) {
        std::cin >> x;
        if (x & 1)odd++;
        else even++;
    }
    if (odd != even) {
        std::cout << 0 << '\n';
        return;
    }
    odd = even = 0;
    std::vector<int> A;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] & 1)odd++;
        else even++;
        if (odd == even) {
            A.push_back(std::abs(a[i] - a[i + 1]));
        }
    }
    std::sort(A.begin(), A.end());
    int ans = 0;
    for (auto &x: A) {
        if (B >= x) {
            B -= x;
            ans++;
        } else break;
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