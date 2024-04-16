#include<bits/stdc++.h>
using namespace std;
#define maxn 110000
int n,k,fa[maxn][20],dep[maxn],dlt[maxn];
vector<int>v[maxn];
int maxx;
void dfs(int x){
	for(int i  =1;i <= maxx;i ++)
	{
		fa[x][i] = fa[fa[x][i - 1]][i - 1];
	}
	for(int i = 0;i < v[x].size(); ++i){
		int u = v[x][i];
		if(u != fa[x][0]){
			fa[u][0] = x;
			dep[u] = dep[x] + 1;
			dfs(u);
		}
	}
	return ;
}
void dfs1(int x){
	for(int i = 0;i < v[x].size();++i) {
		int u = v[x][i];
		if(u != fa[x][0]){
			dfs1(u);
			dlt[x] +=dlt[u];
		}
	}
}
int lca(int u,int v)
{
	if(dep[u] < dep[v])swap(u,v);
	int delta = dep[u] - dep[v];
	for(int x = 0;x <= maxx;++x) {
		if((1 << x) & delta){
			u = fa[u][x];
		}
	}
	if(u == v)return u;
	for(int x = maxx;x >= 0;--x){
		if(fa[u][x]!=fa[v][x]){
			u = fa[u][x];
			v = fa[v][x];
		}
	}
	return fa[u][0];
}

int main()
{
	scanf("%d%d",&n,&k);
	maxx = log2(n);
	for(int i = 1;i < n;i ++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b),v[b].push_back(a);
	}
	dfs(1);
	for(int i = 1;i <= k; ++i) {
		int a,b;
		scanf("%d%d",&a,&b);
		dlt[a]++,dlt[b]++;
		int c = lca(a,b);
		dlt[c]--;dlt[fa[c][0]]--;
	}
	dfs1(1);
	for(int i = 1;i <= n;++ i)cout << dlt[i] << ' ';
	cout << endl;
	return 0;
}
