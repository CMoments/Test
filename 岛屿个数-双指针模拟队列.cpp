#include<bits/stdc++.h>
using namespace std;

typedef pair<char,char>PII;
const int N = 55;

char g[N][N];
bool vis[N][N];
int m,n;
int cnt = 1;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

PII q[N*N];

bool dfs(int px,int py)
{
	if(px == 0 || px == m - 1 || py == 0 || py == n -1)
		return true;
	vis[px][py] = true;
	
	for(int i = -1;i <= 1;i++)
	{
		for(int j = -1;j <= 1;j++)
		{
			int x = px + i;
			int y = py + j;
			
			if(x >= 0 && x < m && y >= 0 && y < n)
			{
				if(!vis[x][y] && ( g[x][y] =='0' || g[x][y] == '1' + cnt))
				{
					if(dfs(x,y))return true;
				}
			}
		}
	}
	return false;
}

void bfs(int px,int py)
{
	int hh = 0,tt = 0;
	q[tt++] = {px,py};
	g[px][py] = '1' + cnt;
	
	while(hh < tt)
	{
		PII t = q[hh++];
		
		for(int i = 0;i < 4;++ i)
		{
			int x = t.first + dx[i];
			int y = t.second + dy[i];
			//判断是否属于岛屿，如果属于岛屿则入队
			if(x >= 0 && x < m && y >= 0 && y < n)
			{
				if(g[x][y] == '1')
				{
					g[x][y] = '1' + cnt;
					q[tt++] = {x,y};
				}
			}
		}
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	
	while(T--)
	{
		scanf("%d%d",&m,&n);
		
		for(int i = 0;i < m;++ i)scanf("%s",g[i]);
		
		int res = 0;
		cnt = 1;
		for(int i = 0;i < m;++ i)
		{
			for(int j = 0;j < n;++ j)
			{
				if(g[i][j] == '1'){
					bfs(i,j);
					memset(vis,0,sizeof(vis));
					if(dfs(i,j))res++;
					cnt++;
				}
			}
		}
		cout << res << endl;
	}
	
	
	
	return 0;
}
