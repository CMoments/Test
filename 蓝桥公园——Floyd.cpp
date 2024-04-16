#include<iostream>
using namespace std;
using ll = long long;
const int N = 405;
const ll inf = 2e18;
ll d[N][N];

int main()
{
	
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,q;cin >> n >> m >> q;
	for(int i = 1;i <= n;++i){
		for(int j = 1;j <= n;++j)
		{
			d[i][j] = inf;
		}
	}
	//每个点到自己的距离为0
	for(int i = 1;i <= n;++ i)d[i][i] = 0;
	while(m --)
	{
		ll u,v,w;cin >> u >> v >> w;
		d[u][v] = min(d[u][v],w);
		d[v][u] = min(d[v][u],w);
	}
	for(int k = 1;k <= n;++k)
	{
		for(int i = 1;i <= n;++ i)
		{
			for(int j = 1;j <= n;++ j)
			{
				d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
			}
		}
	}
	while(q --)
	{
		int st,ed;cin >> st >> ed;
		cout << (d[st][ed] >= inf ? -1:d[st][ed]) << endl;
	}
	
	return 0;
}
