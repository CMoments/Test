
#include <bits/stdc++.h>
using namespace std;
const int M = 1005;
struct PII
{
	int first;
	int second;
};
// C++ 有个数据类型叫 pair 上面的就可以定义为 pair<int,int> 用起来比较方便。
PII tempPair;//临时结点
char Map[M][M];
//---------图的路径搜索常用方向移动表示-------
int dx[4]= {0,1,-1,0};
int dy[4]= {1,0,0,-1};
// 两两组合形成上下左右四个方向
//      1------------------> x
//      |
//      |
//      |
//      |
//      |
//      |
//      |
//      ↓
//      y

// dx[0]=0 dy[0]=1 那么代表向下的方向

// dx[1]=1 dy[1]=0 那么代表向右的方向

// dx[2]=-1 dy[0]=0 那么代表向左的方向

// dx[3]=0 dy[1]=-1 那么代表向上的方向

int n;// n 行
int m;// m 列
int k;// k 次

queue<PII > q; //广度优先搜索所用的队列

int len;//记录节点数量方便后续k的计算
bool pd(int x, int y)
{
	if(x<1)
		return 0;
	// /x 轴坐标 左侧越界
	else if(x>n)
		return 0;
	//x 轴坐标 右侧越界
	else  if(y<1)
		return 0;
	//y 轴坐标 上侧越界
	else if(y>m)
		return 0;
	//y 轴坐标 下侧越界
	else if(Map[x][y]=='g')
		return 0;
	//已经长草了
	else return 1;
	// 在范围内，且没长草
}

void BFS()
{
	//BFS
	while(!q.empty()&&k>0)
	{
		tempPair = q.front();
		q.pop();
		//这两步是取出队首的节点
		
		int x = tempPair.first;//横坐标
		int y = tempPair.second;//纵坐标
		
		for(int i=0; i<4; i++)
		{
			int nowx = x+dx[i]; //扩展后的横坐标
			int nowy = y+dy[i]; //扩展后的纵坐标
			
			if(pd(nowx,nowy))
			{
				q.push({nowx,nowy});
				Map[nowx][nowy]='g';
			}
			//符合要求执行扩展，不符合要求，忽略即可。
		}
		
		len--; //没取出一个节点len  -1
		if(len==0)
		{
			//当len =0 时，代表当前层扩展完了，那么就代表第一个月扩展完了
			k--; // 所以k--
			len = q.size(); // 当前层扩展完了，那就该扩展下一层了，所以len又被赋值为下一层的节点数目的值
		}
	}
}
int main()
{
	cin>>n>>m;
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			cin>>Map[i][j];
			if(Map[i][j]=='g')
			{
				tempPair.first=i;
				tempPair.second=j;
				// cout<<i<<""<<j<<endl;
				q.push(tempPair);//将初始有树的结点加入队列
			}
		}
	}
	
	len = q.size();//记录第一层的节点数量方便后续k的计算
	cin>>k;
	BFS();
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			cout<<Map[i][j];
		}
		
		cout<<endl;
	}
	return 0;
}
