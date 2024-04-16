#include<bits/stdc++.h>
using namespace std;

using ll = long long ;
const ll p = 1e9 + 7;
const int inf = 1e9 ,N = 55;

int n,m,k,c[N][N];

int dx[] = {0,1};
int dy[] = {1,0};


int dp[N][N][15][15];  //大约1e6种状态，数组可以接受

bool inmp(int x,int y)
{
	return 1 <= x && x <= n && 1 <= y && y <= m;
}

ll dfs(int x,int y,int mx, int cnt)
{
	if( x == n && y == m )return (ll)(cnt == k);
	if(dp[x][y][mx][cnt] != -1)return dp[x][y][mx][cnt];
	
	ll res = 0;
	
	for(int i = 0;i < 2;i ++)
	{
		int nx = x + dx[i], ny = y + dy[i];
		
		if(!inmp(nx,ny))continue;
		
		//拿上这个宝贝
		if(c[nx][ny] > mx && cnt < k)res = (res + dfs(nx,ny,c[nx][ny],cnt + 1)) % p;
		
		//不拿这个宝贝
		res = (res + dfs(nx,ny,mx,cnt)) % p;
		
	}
	return dp[x][y][mx][cnt] = res;
}

int main()
{
	memset(dp,-1,sizeof dp);
	cin >> n >> m >> k;
	
	for(int i = 1;i <= n;i ++){
		for(int j = 1;j <= m;j ++)
		{
			cin >> c[i][j];
			c[i][j] ++;   //整体加1不影响结果，这样对mx可以设置初值为0，避免数组越界到-1
		}
	}
	cout << (dfs(1,1,0,0) + dfs(1,1,c[1][1],1)) % p;
	
	return 0;
}
