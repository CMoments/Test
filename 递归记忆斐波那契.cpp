#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll p = 1e9 + 7;
const int inf = 1e9,N = 1e5 + 3;
ll dp[N];

ll f(int n)
{
	if(n <= 2)return 1;
	if(dp[n] != -1)return dp[n];
	
	return dp[n] = (f(n - 1) + f(n - 2)) % p;
}


int main()
{
	memset(dp,-1,sizeof dp);
	int n;cin >> n;
	cout << f(n) << endl;
	
	return 0;
}
