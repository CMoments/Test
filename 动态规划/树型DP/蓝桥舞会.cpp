#include <bits/stdc++.h>
using namespace std;
const int N=100005;
int n,a[N];
long long dp[N][2];
vector<int> e[N];
void dfs(int u)
{
	for (auto v:e[u])
	{
		dfs(v);
		dp[u][1]+=dp[v][0];
		dp[u][0]+=max(dp[v][0],dp[v][1]);
	}
	dp[u][1]+=a[u];
}
int main()
{
	cin>>n;
	set<int> st;
	for (int i=1;i<=n;i++) cin>>a[i],st.insert(i);
	for (int i=1,x,y;i<n;++i)
	{
		cin>>x>>y;
		e[y].push_back(x);
		st.erase(x);
	}
	int rt=*st.begin();
	dfs(rt);
	cout<<max(dp[rt][0],dp[rt][1]);
	return 0;
}
