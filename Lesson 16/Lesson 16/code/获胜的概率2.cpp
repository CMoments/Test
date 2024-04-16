#include <bits/stdc++.h>

using LL = long long;
using Pair = std::pair<int, int>;

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

struct Matrix {
    std::array<std::array<Z, 10>, 10> a;

    Matrix() : a{} {}

    Matrix operator*(const Matrix &A) const {
        Matrix ret;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                for (int k = 0; k < 10; k++) {
                    ret.a[i][j] += a[i][k] * A.a[k][j];
                }
            }
        }
        return ret;
    }

    Matrix qpow(LL n) const {
        Matrix ret, mul = *this;
        for (int i = 0; i < 10; i++)ret.a[i][i] = 1;
        while (n > 0) {
            if (n & 1)ret = ret * mul;
            mul = mul * mul, n >>= 1;
        }
        return ret;
    }
};

void solve(const int &Case) {
    int n;
    LL k;
    std::cin >> n >> k;
    Matrix A;
    for (int i = 0; i < n; i++) {
        int t;
        std::cin >> t;
        Z inv = Z{t}.inverse();
        while (t--) {
            int x;
            std::cin >> x;
            A.a[x - 1][i] = inv;
        }
    }
    Matrix ans = A.qpow(k);
    for (int i = 0; i < n; i++) {
        std::cout << ans.a[i][0] << '\n';
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