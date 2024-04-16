#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll p = 1e9 + 7;
const int inf = 1e9,N = 1e3 + 3;

int n,m,k,sx,sy,fx,fy,h[N][N];


int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

bool inmp(int x,int y)
{
	return 1 <= x && x <= n && 1 <= y && y <= m;
}

//返回值表示能否到达终点(fx,fy),t表示当前使用的喷气背包的次数

bool dfs(int x,int y,int t)
{
	if(x == fx && y == fy)return true;
	
	for(int i = 0;i < 4 ;i ++)
	{
		int nx = x + dx[i],ny = y + dy[i];
		
		if(!inmp(nx,ny))continue;
		
		if(!t)
		{
			//不用
			if(h[x][y] > h[nx][ny] && dfs(nx,ny,0))return true;
			
			if(h[x][y] + k > h[nx][ny] && dfs(nx,ny,1))return true;
		}else
		{
			if(h[x][y] > h[nx][ny] && dfs(nx,ny,1))return true;
		}
	}
	return false;
}

int main()
{
	cin >> n >> m >> k;
	cin >> sx >> sy >> fx >> fy;
	for(int i = 1;i <= n;i ++){
		for(int j = 1;j <= m;j ++)
		{
			cin >> h[i][j];
		}
	}
	
	cout << (dfs(sx,sy,0)?"Yes" : "No") << '\n';
	return 0;
}
