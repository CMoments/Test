// 4
// 2 12 2 2
// 2 * 12 + 2 - 2
// 2 * 12 * 2 / 2
// 2 * 2 * 12 / 2
// 2 / 2 * 12 * 2
// ...
// 12 * 2 * 2 / 2 (字典序最小)

// 枚举 n 个数的排列，再枚举相邻数之间的运算符，时间复杂度为 O(n! 4^n)
// 通过每次限制搜索的都是当前字典序最小值，在保证答案的字典序最小后，可以以一个比较玄学的速度求出答案

#include <bits/stdc++.h>

using LL = long long;
using ld = long double;
using Pair = std::pair<ld, ld>;
#define inf 1'000'000'000

struct Frac {
    LL x, y; // x 是分子，y 是分母

    Frac() : x(0), y(1) {}

    Frac(LL X, LL Y) : x(X), y(Y) {
        LL g = std::gcd(x, y);
        x /= g;
        y /= g;
        // 约分
    }

    Frac operator+(const Frac &rhs) const {
        return Frac{x * rhs.y + y * rhs.x, y * rhs.y};
    }

    Frac operator-(const Frac &rhs) const {
        return Frac{x * rhs.y - y * rhs.x, y * rhs.y};
    }

    Frac operator*(const Frac &rhs) const {
        return Frac{x * rhs.x, y * rhs.y};
    }

    Frac operator/(const Frac &rhs) const {
        return Frac{x * rhs.y, y * rhs.x};
    }
};

void solve(const int &Case) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto &i: a)std::cin >> i;
    // * + - / 0 1 2 ...
    std::sort(a.begin(), a.end(), [&](const int &x, const int &y) { // 字典序排序
        if (x < 10 && y < 10)return x < y;
        if (x >= 10 && y >= 10)return x < y;
        if (x < 10 && y >= 10) {
            if (x == 1)return true;
            return false;
        }
        if (y == 1)return false;
        return true;
    });
    const std::array<char, 4> op = {'*', '+', '-', '/'};
    std::vector<int> A(n); // 枚举的运算符
    std::vector<Frac> f(n); // 枚举的数字
    std::vector<int> vis(n); // 判断一个数是否被枚举过
    std::function<void(int)> dfs = [&](int dep) {
        if (dep == n - 1) { // 此时已经枚举了 n - 1 个数和所有运算符，最后一个数可以被直接确定
            auto g = f;
            for (int i = 0; i < n; i++) {
                if (!vis[i]) { // 获得最后一个数是谁，一定是没被枚举过的数
                    f[dep] = g[dep] = Frac(a[i], 1);
                    break;
                }
            }
            // 2 * 3 * 5
            //     6 * 5
            for (int i = 0; i < n - 1; i++) { // 乘除优先，先计算乘除
                if (A[i] == 0) { // 乘
                    g[i + 1] = g[i] * g[i + 1];
                    g[i].x = -1;
                }
                else if (A[i] == 3) { // 除
                    g[i + 1] = g[i] / g[i + 1];
                    g[i].x = -1;
                }
            }
            Frac ans = Frac{0, 1};
            int pre = 1; // 记载上一个符号是谁，第 0 个符号显然是 +，数字表达式的意义
            for (int i = 0; i < n; i++) {
                if (g[i].x == -1) {
                    continue;
                }
                if (pre == 1) { // 加
                    ans = ans + g[i];
                    pre = A[i]; // 更新运算符
                }
                else { // 减
                    ans = ans - g[i];
                    pre = A[i]; // 更新运算符
                }
            }
            if (ans.x == 24 * ans.y) {
                std::cout << "YES\n";
                for (int i = 0; i < n; i++) {
                    std::cout << f[i].x;
                    if (i != n - 1) {
                        std::cout << op[A[i]];
                    }
                }
                std::cout << "=24\n";
                exit(0);
            }
            return;
        }
        for (int i = 0; i < n; i++) { // 枚举下一个数
            if (vis[i])continue;
            vis[i] = 1;
            f[dep] = Frac(a[i], 1);
            for (int j = 0; j < 4; j++) { // 枚举下一个运算符
                A[dep] = j;
                dfs(dep + 1);
            }
            vis[i] = 0; // 回溯
        }
    };
    dfs(0);
    std::cout << "NO\n";
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