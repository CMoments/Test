#include <bits/stdc++.h>

using ull = unsigned long long;
using Pair = std::pair<int, int>;

const ull base = 233;

const int mod = 111;

void solve(const int &Case) {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    s = s + s;
    n *= 2;
    std::vector<ull> pw(n + 1), has(n + 1);
    pw[0] = 1;
    for (int i = 1; i <= n; i++)pw[i] = pw[i - 1] * base;
    for (int i = 1; i <= n; i++)has[i] = has[i - 1] * base + s[i - 1];
    auto get = [&](int l, int r) {
        return has[r] - has[l] * pw[r - l];
    };
    std::map<ull, int> M;
    for (int i = 0; i < n / 2; i++) {
        M[get(i, i + n / 2)]++;
    }
    std::cout << M.size() << '\n';
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