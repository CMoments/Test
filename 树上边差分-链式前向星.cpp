#include<bits/stdc++.h>
using namespace std;
#define maxn 110000
int n,k,fa[maxn][20],dep[maxn],dlt[maxn];
int cnt,head[maxn];
struct Edge{
	int nex,to,dis;
}edge[maxn<<1];
int maxx,val[maxn];
void dfs(int x)
{
	for(int i = 1;i <= maxx; ++i){
		fa[x][i] = fa[fa[x][i - 1]][i - 1];
	}
	for(int i = head[x];i;i = edge[i].nex){
		int u = edge[i].to;
		if(u != fa[x][0]){
			fa[u][0] = x;
			val[u] = edge[i].dis;
			dep[u] = dep[x] + 1;
			dfs(u);
		}
	}
	return ;
}
void dfs1(int x){
	for(int i = head[x];i;i = edge[i].nex){
		int u = edge[i].to;
		if(u != fa[x][0]){
			dfs1(u);
			dlt[x] += dlt[u];
		}
	}
	return ;
}
int lca(int u,int v){
	if(dep[u] < dep[v])swap(u,v);
	int delta = dep[u] - dep[v];
	for(int x = 0;x <= maxx; ++ x) {
		if((1 << x) & delta){
			u = fa[u][x];
		}
	}
	if(u == v)return u;
	for(int x = maxx;x >= 0;--x) {
		if(fa[u][x] != fa[v][x]){
			u = fa[u][x];
			v = fa[v][x];
		}
	}
	return fa[u][0];
}



int main()
{
	scanf("%d%d",&n,&k);
	maxx=log2(n);
	for(int i = 1;i < n;i ++)
	{
		int a,b,dis;
		scanf("%d%d%d",&a,&b,&dis);
		edge[++cnt].nex = head[a];head[a]=cnt;edge[cnt].to = b;edge[cnt].dis = dis;
		edge[++cnt].nex = head[b];head[b]=cnt;edge[cnt].to = a;edge[cnt].dis = dis;
	}
	dfs(1);
	for(int i = 1;i <= k; ++i){
		int a,b,x;
		scanf("%d%d%d",&a,&b,&x);
		dlt[a]+=x;dlt[b]+=x;
		int c = lca(a,b);
		dlt[c]-=2 * x;
	}
	dfs1(1);
	for(int i = 1;i <= n; ++ i)cout << dlt[i] << " ";
	cout << endl;
	return 0;
}
