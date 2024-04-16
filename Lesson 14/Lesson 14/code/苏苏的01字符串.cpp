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
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    Z ans = 0;
    Z inv2 = Z{2}.inverse();
    Z f = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == '0') {
            f = 0;
            ans += 1;
        }
        else if (s[i - 1] == '1') {
            f = f + 1;
            ans += 2 * f;
        }
        else {
            f = (f + 1) * inv2;
            ans += 2 * f + inv2;
        }
    }
    std::cout << ans - n << '\n';
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