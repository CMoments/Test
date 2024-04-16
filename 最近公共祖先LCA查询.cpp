#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int dep[N],fa[N][24];
vector<int> g[N];

void dfs(int x,int p)
{
	dep[x] = dep[p] + 1;
	fa[x][0] = p;
	for(int i =1 ;i <= 20;++ i)fa[x][i] = fa[fa[x][i - 1]][i - 1];
	for(const auto &y : g[x])
	{
		if(y == p)continue;
		dfs(y,x);
	}
	
}
int lca(int x,int y)
{
	if(dep[x] < dep[y])swap(x,y);
	for(int i = 20;i >= 0; -- i)if(dep[fa[x][i]] >= dep[y])x = fa[x][i];
	if(x == y)return x;
	for(int i = 20;i >= 0; -- i)if(fa[x][i] != fa[y][i])x = fa[x][i],y = fa[y][i];
	return fa[x][0];
}

int main()
{
	int n;cin>> n;
	for(int i = 1;i < n;++i )
	{
		int u,v;cin >> u >> v;
		g[u].push_back(v),g[v].push_back(u);
	}
	dfs(1,0);
	int m;cin >> m;
	while(m --)
	{
		int x,y;cin >> x >> y;
		cout << lca(x,y)<< endl;
	}
	
	return 0;
}
