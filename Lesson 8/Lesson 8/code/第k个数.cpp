// 字典序是逐位比较，求第 k 小，想到枚举前缀，其实类似于数位 dp
// 举个例子，n = 101, k = 13
// 枚举第一位是 1，那么我们要考虑第一位是 1 的时候有几个数，假设有 C 个数
// 如果 C >= k，那么第 k 小的数的第一位也一定是 1
// 如何求 C 呢？
// 此时我们已经枚举了前缀 x，接下来枚举一共有几位数，来求得这个前缀的数的个数
// 用 x 加一后，与 x 一起不断添加 0 作差来获得个数
// 先枚举一位数，即以 1 为前缀的一位数有几个，(1 + 1) - 1 = 1
// 再枚举两位数，即以 1 为前缀的两位数有几个，(1 + 1)0 - 10 = 10
// 再枚举三位数，即以 1 为前缀的三位数有几个，min((1 + 1)00, n + 1) - 100 = 102 - 100 = 2
// 于是 C = 1 + 10 + 2 = 13 >= k
// 所以第一位数一定是 1
// 同时答案肯定不是 1，因为 k 不是 1，所以 k = k - 1 = 12 (这里的意思就是将 1 去除，因为接下来要枚举以 10 为前缀，而 1 不在其中)
// 接下来枚举第二位数是 0
// 先枚举两位数，即以 10 为前缀的两位数有几个，(10 + 1) - 10 = 1
// 再枚举三位数，即以 10 为前缀的三位数有几个，min((10 + 1)0, n + 1) - 100 = 2
// 于是 1 + 2 < 12 = k，说明第二位数一定不是 0，k = k - (1 + 2) = 9 (这里的意思是将 10 为前缀的去除)
// 接下来枚举第二位数是 1
// 先枚举两位数，即以 11 为前缀的两位数有几个，(11 + 1) - 11 = 1
// 于是 1 < 12 = k，说明第二位数一定不是 1，k = k - 1 = 8
// 以此类推，到枚举第二位数是 9，此前 k = 1
// 先枚举两位数，即以 19 为前缀的两位数有几个，(19 + 1) - 19 = 1
// 于是 1 >= k = 1，说明第二位数是 9，因为 k = 1，所以答案就是 19
// 其他也相同处理

#include <bits/stdc++.h>

using LL = long long;
using Pair = std::pair<int, int>;
#define inf 1'000'000'000

void solve(const int &Case) {
    int n, k;
    std::cin >> n >> k;
    int now = 1;
    auto calc = [&](LL pre) { // 注意 long long
        LL nxt = pre + 1;
        LL sum = 0;
        while (pre <= n) {
            sum += std::min((LL) n + 1, nxt) - pre;
            pre *= 10, nxt *= 10;
        }
        return sum;
    };
    while (k > 0) {
        LL cnt = calc(now);
        if (cnt >= k) {
            if (k == 1) {
                std::cout << now << '\n';
                return;
            }
            k--;
            now *= 10;
        }
        else {
            k -= cnt;
            now++;
        }
    }
    std::cout << now << '\n';
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