#include <bits/stdc++.h>
using namespace std;
#define maxn 110000
int n, val[maxn];
struct Edge
{
	int nex, to;
}edge[maxn << 1];
int head[maxn], cnt;
int f[maxn][2];
void add(int from, int to)
{
	edge[++cnt].nex = head[from];//当前这条从from出发的边上一条边的编号
	head[from] = cnt;  //从from出发的最新的一条边的编号
	edge[cnt].to = to;   //当前边是到to去的
	return ;
}
void dfs(int u, int fa)
{
	for (int i = head[u]; i; i = edge[i].nex)
	{
		int v = edge[i].to;
		if (v == fa)
			continue;
		dfs(v, u);
		f[u][0] += max(f[v][0], f[v][1]);
		f[u][1] += f[v][0];
	}
	return ;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i )
		scanf("%d", &val[i]), f[i][1] = val[i];
	for (int i = 1; i < n; ++ i )
	{
		int u, v;
		scanf("%d%d", &u, &v);
		add(u, v), add(v, u);
	}
	dfs(1, 0);
	printf("%d\n", max(f[1][0], f[1][1]));
	return 0;
}
