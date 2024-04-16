#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll p  = 1e9+7;
const int N = 2e5+9;
vector<int> g[N];
ll d[N],dp[N];
void bfs()
{
	bitset<N> vis; 
	memset(d,0x3f,sizeof(d));//初始化从1到i点的距离为无穷。d[y]=min(d[y],d[x]+1);
	queue<int> q;
	q.push(1);
	d[1]=0;
	dp[1]=1;
	while(q.size())
	{
		int x=q.front();q.pop();
		if(vis[x]) continue;
		vis[x]=true;
		for(const auto & y : g[x])
		{
			if(d[x]+1>d[y]) continue;
			else if(d[x]+1==d[y]) dp[y]=(dp[x]+dp[y])%p;
			else d[y]=d[x]+1,dp[y]=dp[x];
			q.push(y);
		}
	}
}
int main()
{
	int n,m;cin>>n>>m;
	while(m--)
	{
		int x,y;cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	bfs();
	cout<<dp[n]<<endl;
}
