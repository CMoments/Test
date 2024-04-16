#include<bits/stdc++.h>
using namespace std;
#define maxn 110000
#define ll long long
int n,c[maxn],dist[maxn];
struct Edge{
	int nex,to,dis;
}edge[maxn<<1];
int siz[maxn],head[maxn],cnt,tot;
void add(int from,int to,int dis){
	edge[++cnt]={head[from],to,dis};
	head[from]=cnt;
	return ;
}
int sum[maxn];
ll f[maxn];    
void dfs(int x,int fa){
	siz[x]=1;sum[x]=c[x];
	for(int i=head[x];i;i=edge[i].nex){
		int v=edge[i].to;
		if(v==fa)continue;
		dist[v]=dist[x]+edge[i].dis;
		dfs(v,x);
		siz[x]+=siz[v];
		sum[x]+=sum[v];
	}
	return ;
}
void dfs1(int x,int fa){
	for(int i=head[x];i;i=edge[i].nex){
		int v=edge[i].to;
		if(v==fa)continue;
		f[v]=f[x]-sum[v]*edge[i].dis+(tot-sum[v])*edge[i].dis;
	}
	return ;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&c[i]),tot+=c[i];
	for(int i=1;i<n;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		add(a,b,c);add(b,a,c);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++){
		f[1]+=dist[i]*c[i];
	}
	dfs1(1,0);
	ll ans=101010101000;
	for(int i=1;i<=n;i++){
		ans=min(ans,f[i]);
	}
	cout<<ans<<endl;
	return 0;
}
