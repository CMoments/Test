#include <bits/stdc++.h>

using LL = long long; // [-2^{61}, 2^{61} - 1]
using ld = long double;
using unl = __int128; // [-2^{127}, 2^{127} - 1]
// __int128 不能用 cin 读入，也不能 cout 输出，scanf / printf 更是不行
using Pair = std::pair<int, int>;
#define inf 1'000'000'000'000'000'000ll

struct P {
    int A, B;
    unl C;

    inline bool operator < (const P &rhs) const { // 重载运算符，定义这个 P 结构体的大小关系
        return B < rhs.B;
    }
};

void solve(const int &Case) {
    int n;
    std::cin >> n;
    std::vector<P> a(n);
    for (auto &[A, B, C] : a) {
        std::cin >> A >> B;
        // 只能读入 long long，然后强转成 __int128
        // 或者读入字符串，然后一个个字符转成 __int128
        LL c;
        std::cin >> c;
        C = c;
    }
    std::sort(a.begin(), a.end());
    int V = 1'000'00;
    std::vector<unl> f(V, -inf);
    f[0] = 0;
    for (const auto &[A, B, C]: a) {
        auto g = f;
        std::vector<unl>(V, -inf).swap(f);
        for (int i = 0; i < V; i++) {
            f[i] = g[i];
            if (i >= A && i <= B) {
                f[i] = std::max(f[i], g[i - A] + C);
            }
        }
    }
    unl ans = *std::max_element(f.begin(), f.end());
    std::function<void(unl)> print = [&](unl x) { // __int128 专属的输出方式，其实 long long 之类的也可以这样输出
        if (x >= 10)print(x / 10);
        std::cout << char(x % 10 + '0');
    };
    print(ans);
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