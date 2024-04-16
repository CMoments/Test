#include<bits/stdc++.h>
using namespace std;
const int N = 105;
using ll = long long;
const ll p = 1e6 + 7;
ll a[N],dp[N][N];

int main()
{
	int n,m; cin >> n >> m;
	for(int i = 1;i <= n; i ++)cin >> a[i];
	
	dp[0][0] = 1;
	
	for(int i = 1;i <= n;i ++)
	{
		for(int j = 0;j <= m;j ++)
		{
			for(int k = 0;k <= a[i] && k <= j; k ++){
				dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % p;
			}
		}
	}
	cout << dp[n][m] << endl;
	return 0;
}

