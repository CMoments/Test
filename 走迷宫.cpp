
#include <bits/stdc++.h>
using namespace std;

int vis[150][150]; //用于存储是否访问过，并且存储长度

char G[150][150]; //用于存储题目给出的地图

int n,m,ans=0;

int dx[4] = {0,0,-1,1};

int dy[4] = {1,-1,0,0};

//上下左右移动，不会的看前面的代码

struct node
{
	int x;
	int y;
};

node Start,End;
bool pd(int x,int y)
{
	
	
	if(x<1)
		return 0;
	//从左侧走出方格
	
	else if(x>n)
		return 0;
	//从右侧走出方格
	
	else if(y<1)
		return 0;
	//从上侧走出方格
	
	else if(y>m)
		return 0;
	//从下侧走出方格
	
	else if( vis[x][y]!=0)
		//已经访问了
		return 0;
	else if(G[x][y]!='1') return 0;
	//不是路不能走
	else return 1;
}

bool  check(int x, int y)
{
	
	if(x == End.x&& y == End.y)   //找到终点，把距离给他
	{
		ans  =  vis[x][ y];
		return 1;
	}
	
	else    return 0;
	
}
void bfs()
{
	queue<node>q;
	
	node now,next;
	
	q.push(Start);     //将起点压人队列中
	
	vis[Start.x][Start.y] = 1;
	
	while(!q.empty())
	{
		now = q.front();
		
		if(check(now.x,now.y))
			return ;
		
		q.pop();     //将队列最前面的弹出。
		
		for(int i=0; i<4; i++)  //四个方向
		{
			
			int nextx = now.x + dx[i];
			int nexty = now.y + dy[i];
			
			if(pd(nextx,nexty))  //判断是否符合条件
			{
				
				next.x=nextx;
				next.y=nexty;
				
				q.push(next);
				
				vis[nextx][nexty] = vis[now.x][now.y]+1; //步数+1
			}
		}
	}
}
int main()
{
	cin>>n>>m;
	//memset(vis,0,sizeof(vis));
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			cin>>G[i][j];
		}
	}
	
	cin>>Start.x>>Start.y>>End.x>>End.y;
	
	ans = 0;
	
	bfs();
	cout<<ans-1<<endl;
	
	return 0;
}

