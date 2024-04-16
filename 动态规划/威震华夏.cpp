#include <bits/stdc++.h>

using LL = long long;
using ld = long double;
using Pair = std::pair<LL, int>;
#define inf 1'000'000'000'000'000'000ll

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

const int kcz = 1'000'000'00;
using Z = ModInt<kcz>;

void solve(const int &Case) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        int S = 0;
        for (int j = 0; j < n; j++) {
            int x;
            std::cin >> x;
            S |= x << j;
        }
        a[i] = S;
    }
    std::vector<int> ban(1 << n);
    for (int S = 0; S < 1 << n; S++) {
        for (int i = 0; i < n - 1; i++) {
            if ((S >> i & 1) && (S >> (i + 1) & 1)) {
                ban[S] = 1;
                break;
            }
        }
    }
    std::vector<Z> f(1 << n);
    f[0] = 1;
    for (int i = 0; i < n; i++) {
        auto g = f;
        std::vector<Z>(1 << n).swap(f);
        for (int S = a[i]; S > 0; S = (S - 1) & a[i]) {
            if (ban[S])continue;
            int T = S ^ ((1 << n) - 1);
            for (int nS = T; nS > 0; nS = (nS - 1) & T) {
                f[S] += g[nS];
            }
            f[S] += g[0];
        }
        int T = 0 ^ ((1 << n) - 1);
        for (int nS = T; nS > 0; nS = (nS - 1) & T) {
            f[0] += g[nS];
        }
        f[0] += g[0];
    }
    std::cout << std::accumulate(f.begin(), f.end(), Z(0)) << '\n';
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