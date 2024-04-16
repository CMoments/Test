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

const int kcz = 998244353;
using Z = ModInt<kcz>;

struct Matrix {
    std::vector<std::vector<Z>> a;
    int n;

    Matrix(int n) : n(n), a(n, std::vector<Z>(n, 0)) {}

    void read() {
        for (int i = 0; i < n; i++)for (int j = 0; j < n; j++)std::cin >> a[i][j];
    }

    void ast(int i, Z v) {
        for (int k = 0; k < n; k++)a[i][k] *= v;
    }

    void dec(int i, int j, Z v) {
        for (int k = i; k < n; k++)a[i][k] -= a[j][k] * v;
    }

    void print() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)std::cout << a[i][j] << " ";
            std::cout << '\n';
        }
    }

    Z det() {
        Z ans = 1;
        for (int i = 0; i < n; i++) {
            int k = i;
            for (int j = i; j < n; j++)
                if (a[j][i] != 0) {
                    k = j;
                    break;
                }
            if (a[k][i] == 0)return Z{0};
            for (int j = k + 1; j < n; j++)
                if (a[j][i] != 0 && a[j][i] < a[k][i])k = j;
            if (i != k)std::swap(a[i], a[k]), ans = -ans;
            for (int j = i + 1; j < n; j++) {
                if (a[j][i] > a[i][i])std::swap(a[i], a[j]), ans = -ans;
                while (a[j][i] != 0) {
                    dec(i, j, a[j][i].x / a[i][i].x);
                    std::swap(a[i], a[j]);
                    ans = -ans;
                }
            }
        }
        for (int i = 0; i < n; i++)ans *= a[i][i];
        return ans;
    }
};

void solve(const int &Case) {
    int n;
    std::cin >> n;
    Matrix A(n);
    A.read();
    std::cout << A.det() << '\n';
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