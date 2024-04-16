#include <bits/stdc++.h>
using namespace std;
const int N=100005;
vector<int>e[N];
long long a[N],dp[N][3];
int d[N];
int n;
void dfs(int u)
{
	long long minn=1e18;
	for (auto v:e[u])
	{
		dfs(v);
		dp[u][0]+=min({dp[v][0],dp[v][1],dp[v][2]});
		dp[u][1]+=min(dp[v][0],dp[v][1]);
		minn=min(minn,dp[v][0]-min(dp[v][0],dp[v][1]));
		dp[u][2]+=dp[v][1];
	}
	dp[u][0]+=a[u];
	dp[u][1]+=minn;
}
int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin>>n;
	for (int i=1;i<=n;++i)
	{
		int id,m;
		cin>>id;
		cin>>a[id];
		cin>>m;
		while (m--)
		{
			int x;
			cin>>x;
			e[id].push_back(x);
			d[x]++;
		}
	}
	int rt;
	for (int i=1;i<=n;++i)
		if (d[i]==0) rt=i;
	dfs(rt);
	cout<<min(dp[rt][0],dp[rt][1]);
	return 0;
}
}
