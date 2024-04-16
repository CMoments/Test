//本题的构造思路很巧妙,需要深入理解dfs和连通块的特点
//通过观察可以发现,对于每一个矩阵,备选答案只能是0、1、2
//(1)若图本来就不连通,那么无需再添加路障,输出0
//(2)若图有很多条路径可以到达终点,为了用最少的路障让图不连通
//应该在起点的右侧和下侧各放一个路障,或者在终点的上侧和左侧各放一个路障,共放2个路障
//(3)只存在一条路径,放一个路障将唯一的路径堵死即可
//第一种情况最好处理,第一遍dfs如果不连通,说明本来就不需要放路障
//较难分辨的是第二种和第三种情况,需要认识到放一个路障只能堵死一条路
//如果存在超过一条路径从起点到达终点,那么只放一个路障不可能同时堵死多条路
//注:此处提到的路径指的是不同路径之间不能有重合的点 
//故进行第二次dfs,不走第一次走过的路,验证是否有第二条完全不重合的路从起点到达终点
//若没有,则放一个路障堵死唯一的路即可;
//否则就必须放两个路障直接堵死起点或终点 
#include <bits/stdc++.h>

using namespace std;

const int N=5e3+100;

string matrix[N];//矩阵迷宫 
bool visit[N][N];//visit[i][j]表示matrix[i][j]之前是否已走过 
int n;//n*n的矩阵 

bool check(int x,int y)//验证matrix[x][y]是否可以走 
{
	if(x<=0||y<=0||x>n||y>n)return false;//超出地图范围,不能走 
	if(matrix[x][y]=='X')return false;//是路障,不能走 
	if(visit[x][y])return false;//之前已经走过,不能走 
	return true;//否则可以走 
}

bool dfs(int x,int y)//从matrix[x][y]开始进行dfs 
{
	if(x==n&&y==n)return true;//到达起点,返回true 
	if(!check(x,y))return false;//不能走,返回false 
	if(x!=1||y!=1)visit[x][y]=true;//不是起点,标记为已走过(起点要反复走,不能做标记)
	//下面开始向4个方向进行dfs,试图探索出一条到达终点的路径
	//由于dfs的特性,只要找到一条可行的路径,就会立即逐层返回true并退出 
	if(dfs(x+1,y))return true;
	if(dfs(x,y+1))return true;
	if(dfs(x-1,y))return true;
	if(dfs(x,y-1))return true;
	
	return false;//不存在可行的路径,返回false 
}

void solve()
{
	memset(visit,0,sizeof(visit));//清空标记数组 
	cin>>n;
	for(int i=1;i<=n;i++)//输入n*n的矩阵迷宫,下标从1开始 
	{
		cin>>matrix[i];
		matrix[i]=" "+matrix[i];    
	}    
	
	if(dfs(1,1)==false)cout<<0<<endl;//第一次dfs就找不到路径,本来就不连通,无需再添加路障 
	else if(dfs(1,1)==false)cout<<1<<endl;
	//第二次dfs不走老路,找不到另一条完全不重合的路径,添一个路障即可 
	else cout<<2<<endl;//否则只能添两个路障,直接把起点或终点堵死 
}

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}
