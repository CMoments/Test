#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 1e6 + 9,p = 1e9 + 7;

ll dp[N],prefix[N];

int main()
{
	int n,k;cin >> n >> k;
	dp[0] = prefix[0] = 1;  //可能存在全都不放的情况
	for(int i = 1;i <= n;i ++)
	{
		if(i - k - 1 < 1)dp[i] = 1;
		else dp[i] = prefix[i - k - 1];
		prefix[i] = (prefix[i - 1] + dp[i]) % p;
	}
	cout << prefix[n] << endl;
	return 0;
}
