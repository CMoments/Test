// i ^ 2 - (i - 1) ^ 2 = 2 * i - 1
// i ^ p - (i - 1) ^ p = F_{p - 1}(i)
// X_i 是个随机变量, 表示第 i 个数它是第几个连续的 1 的随机变量
// P(X_i = j) 表示第 i 个数是第 j 个连续的 1 的概率
// E[X + Y] = E[X] + E[Y]
// 于是答案等价于 E[(\sum_{i = 1} ^ n 2std::max(1 / 2, X_i) - 1)]
// <=> 2\sum_{i = 1} ^ n E[X_i] - n
// 第 i 个数是 0, P(X_i = 0) = 1, E[X_i] = 0
// 第 i 个数是 1, P(X_i = j) = P(X_{i - 1} = j - 1)
// <=> X_i = X_{i - 1} + 1, E[X_i] = E[X_{i - 1} + 1] = E[X_{i - 1}] + 1
// 第 i 个数是 ?, X_i = (X_{i - 1} + 1 + 0) / 2, E[X_i] = E[(X_{i - 1} + 1) / 2] = (E[X_{i - 1}] + 1) / 2

#include <bits/stdc++.h>

using LL = long long;
using ld = long double;
using unl = __int128;
using Pair = std::pair<int, int>;
#define inf 1'000'000'000'000'000ll

template<int kcz>
struct ModInt {
#define T (*this)
    int x;

    ModInt() : x(0) {}

    ModInt(int y) : x(y >= 0 ? y : y + kcz) {}

    ModInt(LL y) : x(y >= 0 ? y % kcz : (kcz - (-y) % kcz) % kcz) {}

    inline int inc(const int &v) {
        return v >= kcz ? v - kcz : v;
    }

    inline int dec(const int &v) {
        return v < 0 ? v + kcz : v;
    }

    inline ModInt &operator+=(const ModInt &p) {
        x = inc(x + p.x);
        return T;
    }

    inline ModInt &operator-=(const ModInt &p) {
        x = dec(x - p.x);
        return T;
    }

    inline ModInt &operator*=(const ModInt &p) {
        x = (int) ((LL) x * p.x % kcz);
        return T;
    }

    inline ModInt inverse() const {
        int a = x, b = kcz, u = 1, v = 0, t;
        while (b > 0)t = a / b, std::swap(a -= t * b, b), std::swap(u -= t * v, v);
        return u;
    }

    inline ModInt &operator/=(const ModInt &p) {
        T *= p.inverse();
        return T;
    }

    inline ModInt operator-() const {
        return -x;
    }

    inline friend ModInt operator+(const ModInt &lhs, const ModInt &rhs) {
        return ModInt(lhs) += rhs;
    }

    inline friend ModInt operator-(const ModInt &lhs, const ModInt &rhs) {
        return ModInt(lhs) -= rhs;
    }

    inline friend ModInt operator*(const ModInt &lhs, const ModInt &rhs) {
        return ModInt(lhs) *= rhs;
    }

    inline friend ModInt operator/(const ModInt &lhs, const ModInt &rhs) {
        return ModInt(lhs) /= rhs;
    }

    inline bool operator==(const ModInt &p) const {
        return x == p.x;
    }

    inline bool operator!=(const ModInt &p) const {
        return x != p.x;
    }

    inline ModInt qpow(LL n) const {
        ModInt ret(1), mul(x);
        while (n > 0) {
            if (n & 1)ret *= mul;
            mul *= mul, n >>= 1;
        }
        return ret;
    }

    inline friend std::ostream &operator<<(std::ostream &os, const ModInt &p) {
        return os << p.x;
    }

    inline friend std::istream &operator>>(std::istream &is, ModInt &a) {
        LL t;
        is >> t, a = ModInt<kcz>(t);
        return is;
    }

    static int get_mod() {
        return kcz;
    }

    inline bool operator<(const ModInt &A) const {
        return x < A.x;
    }

    inline bool operator>(const ModInt &A) const {
        return x > A.x;
    }

#undef T
};

const int kcz = 1'000'000'007;
using Z = ModInt<kcz>;

void solve(const int &Case) {
    std::string s;
    int k;
    std::cin >> s >> k;
    std::reverse(s.begin(), s.end());
    int n = (int) s.size();
    std::vector<std::vector<Z>> f(n, std::vector<Z>(k + 1));
    std::vector<std::vector<int>> vis(n, std::vector<int>(k + 1));
    auto get = [&](const char &ch) {
        if (ch >= '0' && ch <= '9')return ch - '0';
        return ch - 'A' + 10;
    };
    std::function<Z(int, int, int, int)> dp = [&](int dep, int up, int zero, int S) {
        if (__builtin_popcount(S) > k)return Z{0};
        if (dep == -1)return Z(zero == 0 && __builtin_popcount(S) == k);
        if (up == 0 && zero == 0 && vis[dep][__builtin_popcount(S)])return f[dep][__builtin_popcount(S)];
        int lim = get(s[dep]);
        if (!up)lim = 15;
        Z ret = 0;
        for (int i = 0; i <= lim; i++) {
            if (i == 0) {
                if (zero == 1)ret += dp(dep - 1, up && i == lim, zero, S);
                else ret += dp(dep - 1, up && i == lim, 0, S | (1 << i));
            } else ret += dp(dep - 1, up && i == lim, 0, S | (1 << i));
        }
        if (up == 0 && zero == 0) {
            vis[dep][__builtin_popcount(S)] = 1;
            f[dep][__builtin_popcount(S)] = ret;
        }
        return ret;
    };
    std::cout << dp(n - 1, 1, 1, 0) << '\n';
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