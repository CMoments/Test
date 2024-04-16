#include<bits/stdc++.h>
using namespace std;

using ll = long long ;
const int N = 1e5 + 9;
const ll p = 1e9 + 7;
ll dp[N];

bool broken[N];

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin >> n >> m;
	
	for(int i = 1;i <= m;i ++){
		int  x;cin >> x;
		broken[x] = true;
	}
	
	dp[0] = 1;
	if(!broken[1])dp[1] = 1;
	for(int i = 2;i <= n; ++i)
	{
		if(broken[i])continue;
		dp[i] = (dp[i - 1] + dp[i - 2]) % p;
	}
	
	cout << dp[n] << endl;
	
	return 0;
}
