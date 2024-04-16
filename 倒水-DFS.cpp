#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
const int N = 1001;
int n,m,dp[N][N],a[N],b[N],c[N],d[N],e[N];
int dfs(int x,int spv)
{
	int sum = 0;
	if(x < 1)return 0;
	if(dp[x][spv])return dp[x][spv];
	
	if(spv >= c[x]){
		sum = max(dfs(x-1,spv-a[x]) + b[x],max(dfs(x - 1,spv - c[x]) + d[x],dfs(x-1,spv) + e[x]));
	}else if(spv < c[x] && spv >= a[x]){
		sum = max(dfs(x-1,spv-a[x]) + b[x],dfs(x - 1,spv)+e[x]);
	}else{
		sum = dfs(x - 1,spv) + e[x];
	}
	dp[x][spv] = sum;
	return sum;
}


signed main()
{
	scanf("%lld%lld",&n,&m);
	
	for(int i = 1;i <= n; ++ i)
	{
		scanf("%lld%lld%lld%lld%lld",&a[i],&b[i],&c[i],&d[i],&e[i]);
	}
	int res = dfs(n,m);
	printf("%lld",res);
	
	return 0;
}


