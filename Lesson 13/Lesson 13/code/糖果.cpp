#include <bits/stdc++.h>

using LL = long long;
using ld = long double;
using Pair = std::pair<LL, int>;
#define inf 1'000'000'000'000'000'000ll

void solve(const int &Case) {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            int x;
            std::cin >> x;
            x--;
            a[i] |= 1 << x;
        }
    }
    std::vector<int> f(1 << m, n + 1);
    f[0] = 0;
    for (int i = 0; i < n; i++) {
        auto g = f;
        std::vector<int>(1 << m, n + 1).swap(f);
        for (int S = 0; S < 1 << m; S++) {
            f[S] = std::min(f[S], g[S]);
            f[S | a[i]] = std::min(f[S | a[i]], g[S] + 1);
        }
    }
	/*
	 f[a[i]] = 1;
	  f[0] = 0;
	  
	  for(int i = 0;i < n;i ++){
		  for(int j = 1;j < maxx;j ++){
			  f[j|a[i]] = min(f[j]|a[i],f[j]+1);
	  
	  
	*/
    std::cout << (f[(1 << m) - 1] > n ? -1 : f[(1 << m) - 1]) << '\n';
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
