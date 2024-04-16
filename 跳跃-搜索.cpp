#include<bits/stdc++.h>
#define MAX 105
using namespace std;

int n,m,sum = -0x3f3f3f3f;

int map3[MAX][MAX];
int nextt[9][2] = {{0,1},{1,0},{0,2},{2,0},{0,3},{3,0},{1,1},{1,2},{2,1}};

void dfs(int x,int y,int value)
{
	value += map3[x][y];
	if(x == n && y == m)
	{
		sum = max(sum,value);
		return ;
	}
	for(int i = 0;i < 9;++ i)
	{
		int tx = x + nextt[i][0];
		int ty = y + nextt[i][1];
		if(tx <= n && ty <= m)
		{
			dfs(tx,ty,value);
		}
	}
	
}

int main()
{
	cin >> n >> m;
	for(int i = 1;i <= n;++ i)
	{
		for(int j = 1;j <= m;++ j)
		{
			cin >> map3[i][j];
		}
	}
	dfs(1,1,0);
	cout << sum ;
	
	
	return 0;
}



