#include <bits/stdc++.h>
using LL = long long;
using Pair = std::pair<int, int>;
using ld = long double;
using unl = __int128;
#define inf 998244353
//本题的关键是如何读入那么大的数值，如果要记录一个数的值需要很大的空间；而记录一个数的信息只需要 log的空间量
//可以读入一个字符串，存入每个数的数位
void solve(const int &Case) {
	std::string s;
	int k;
	std::cin >> s >> k;
	int n = (int) s.size();
	std::vector<std::vector<LL>> f(n, std::vector<LL>(k));
	std::vector<std::vector<int>> vis(n, std::vector<int>(k));
	std::function<LL(int, int, int, int, const std::vector<int> &)> dp = 
	[&](int dep, int up, int zero,int sum, const auto &a) {
		if (dep == -1) return (LL)((zero ^ 1) && sum == 0); //即是不全为0，又是k的倍数
		if (up == 0 && zero == 0 && vis[dep][sum]) return f[dep][sum];
		int lim = a[dep];
		if (up == 0) lim = 9;
		LL ret = 0;
		for(int i = 0; i <= lim; i++) {
			//ret += dp(dep - 1, up && i == lim, zero && i == 0, (sum + i) % k, a);
			ret = (ret + dp(dep - 1, up && i == lim, zero && i == 0, (sum + i) % k, a)) % inf;
		}
		if(up == 0 && zero == 0) vis[dep][sum] = 1, f[dep][sum] = ret;
		return ret;
	};
	std::vector<int> a;
	for(char i: s) a.push_back(i - '0');
	std::reverse(a.begin(), a.end());
	std::cout << dp(n - 1, 1, 1, 0, a) << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	int T = 1;
	for (int Case = 1; Case <= T; Case++) solve(Case);
	
	
	
	
	return 0;
}
