#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1e3+7,M = 2e4 +7;


ll dp[M];

int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin >> n >> m;
	for(int i = 1;i <= n;i ++)
	{
		ll v,w,s;cin >> v >> w >> s;
		for(int k = 1;k <= s;s -= k,k +=k)
		{
			for(int j = m;j >= k * v;j--)dp[j] = max(dp[j],dp[j - k * v] + k * w);
		}
		
		for(int j = m;j >= s*v;j --)dp[j] = max(dp[j],dp[j - s * v]+ s* w);
	}
	cout << dp[m] << endl;
	return 0;
}
