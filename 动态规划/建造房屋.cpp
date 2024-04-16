#include <iostream>
using namespace std;
using ll=long long;
const ll M=1e9+7;
const int N=1000;
ll dp[N][N]; //dp[j][k]表示截至到第j行，第k个房子的方案数
int main()
{
	int n,m,k;cin>>n>>m>>k;
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k;j++)
		{
			for(int s=1;s<=m&&s<=j-i+1;s++)
				dp[i][j]=(dp[i-1][j-s]+dp[i][j])%M;
		}
	}
	ll ans=0;
	for(int i=1;i<=k;i++)
		ans+=dp[n][i];
	cout<<(ans)%M;
	return 0;
}
