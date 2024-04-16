#include <bits/stdc++.h>

using LL = long long;
using Pair = std::pair<int, int>;
#define inf 1'000'000'000

void solve(const int &Case) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto &x: a)std::cin >> x;
    auto ck = [&]() {
        for (int i = 1; i < n; i++) {
            if (a[i] <= a[i - 1])return false;
        }
        return true;
    };
    if (ck()) {
        std::cout << "1\n";
        return;
    }
    int l = 2, r = n, ret = n;
    while (l <= r) {
        int mid = (l + r) >> 1;
        std::vector<Pair> A;
        int flag = 0;
        std::function<void(int)> push = [&](int x) {
            if (x <= 0) {
                flag = 1;
                return;
            }
            while (!A.empty() && A.back().first > x)A.pop_back();
            if (A.empty()) {
                A.emplace_back(x, 1);
                return;
            }
            if (A.back().first == x) {
                A.back().second++;
                if (A.back().second == mid) {
                    push(x - 1);
                    A.emplace_back(x, 0);
                }
            }
            else {
                A.emplace_back(x, 1);
            }
        };
        A.emplace_back(a[0], 0);
        for (int i = 1; i < n; i++) {
            if (a[i] > a[i - 1])A.emplace_back(a[i], 0);
            else push(a[i]);
            if (flag)break;
        }
        if (flag)l = mid + 1;
        else {
            ret = mid;
            r = mid - 1;
        }
    }
    std::cout << ret << '\n';
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