#include <bits/stdc++.h>
using namespace std;
#define maxn 110
int n, V;
int f[maxn][maxn];
int w[maxn], v[maxn];
vector<int> g[maxn];
struct Edge
{
	int nex, to;
}edge[maxn << 1];
int head[maxn], cnt;
void add(int from, int to)
{
	edge[++ cnt].nex = head[from];
	head[from] = cnt;
	edge[cnt].to = to;
	return ;
}

void dfs(int u, int fa)
{
	memset(f[u], -0x3f, sizeof f[u]);
	if (v[u] <= V)
		f[u][v[u]] = w[u];
	for (int i = head[u]; i; i = edge[i].nex)
	{
		int v = edge[i].to;
		if (v == fa)
			continue;
		dfs(v, u);
		vector<int> nf(f[u], f[u] + V + 1);
		for (int v1 = 0; v1 <= V; v1 ++)
		{
			for (int v2 = 0; v1 + v2 <= V; v2 ++ )
			{
				nf[v1 + v2] = max(nf[v1 + v2], f[u][v1] + f[v][v2]);
			}
		}
		for (int v = 0; v <= V; v ++ )
			f[u][v] = nf[v];
	}
	return ;
}


int main()
{
	scanf("%d%d", &n, &v);
	for (int i = 1; i < n; ++ i )
	{
		int u, v;
		cin >> u >> v;
		add(u, v), add(v, u);
	}
	dfs(1, 0);
	int ans = 0;
	for (int i = 0; i <= V; ++ i )
		ans = max(ans, f[1][i]);
	cout << ans << endl;
	return 0;
}



