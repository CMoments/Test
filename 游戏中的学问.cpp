#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll DP[3100][3100],mod;

int n,k;
int main()
{
	cin >> n >> k >> mod;
	
	
	DP[3][1] = 2;
	
	for(int i = 4;i<=n;++ i)
	{
		for(int j = 1;3 * j <= i && j <= k;++j)
		{
			DP[i][j] = DP[i - 1][j] * (i - 1) % mod;
			
			DP[i][j] = (DP[i][j] + DP[i - 3][j - 1] * (i - 1)*(i - 2)) % mod;
		}
	}
	cout << DP[n][k];	
	
	
	return 0;
}
