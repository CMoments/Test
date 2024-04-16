#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 4000;
const ll mod = 1e9+7;
int n, k;
ll dp[N][N], two[N];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> k >> n;
	for(int i = 1; i <= k; ++ i)
	{
		dp[1][i] = 1;
	}
	if(n == 1)
	{
		cout << k;
		return 0;
	}
	for(int i = 2; i <= n; ++ i)
	{
		for(int j = 1; j <= k; ++ j)
		{
			for(int t = 1; t * t <= j; ++ t)
				// 这里的优化是关键，如果直接枚举从1到j会 t， 而对每一个小于根号j的因数当你找出他的时候就能找到一个对应的大于根号j的因数 因此时间复杂度从O(n3)优化到O(n2 * 根号n） 大概2e8 极限能过
			{
				if(t * t == j) dp[i][j] = (dp[i][j] + dp[i-1][t]) % mod;
				else if(j % t == 0) dp[i][j] = (dp[i][j] + dp[i-1][t] + dp[i-1][j/t]) % mod;
				
			}
		}
	}
	ll ans = 0;
	for(int i = 1; i <= k; ++ i) ans = (ans + dp[n][i]) % mod;
	cout << ans;
	return 0;
}
