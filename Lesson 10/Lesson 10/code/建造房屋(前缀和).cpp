#include <bits/stdc++.h>

using LL = long long;
using ld = long double;
using Pair = std::pair<ld, ld>;
#define inf 1'000'000'000

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
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<Z> f(k + 1, 1);
    for (int i = 1; i <= n; i++) {
        auto g = f;
        std::vector<Z>(k + 1).swap(f);
        for (int j = 1; j <= k; j++) {
            // 原本是 f_{i, j} = f_{i - 1, j - 1} + f_{i - 1, j - 2} + ... + f_{i - 1, j - m}
            // 现在改成前缀和，若 S_{i, j} = f_{i, 0} + f_{i, 1} + ... + f_{i, j}
            // 于是 f_{i, j} = S_{i - 1, j - 1} - S_{i - 1, j - m - 1}
            f[j] = g[j - 1];
            if (j - m - 1 >= 0)f[j] -= g[j - m - 1];
            f[j] += f[j - 1];
        }
    }
    std::cout << f[k] << '\n';
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