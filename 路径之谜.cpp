
#include <bits/stdc++.h>

using namespace std;

struct PII
{
	int first;
	int second;
};

const int N = 30;
int rol[N];
int col[N];
int n;//格子数 长宽从1到n
bool flag[N][N]; //用来标记是否走过
vector<PII> res;


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

//--------------------------------------------

bool  check(int x, int y) //判断走过的路径的箭靶数是否与目标相同
{
	if(x==n && y==n)
	{
		for(int i=1; i<=n; i++)
		{
			if(col[i]!=0)
			{
				return false;
			}
			//如果箭靶上的数目不为0，根据逆推，我们通过当前路径得不到箭靶上的结果
		}
		for(int i=1; i<=n; i++)
		{
			if(rol[i]!=0)
			{
				return false;
			}
			//如果箭靶上的数目不为0，根据逆推，我们通过当前路径得不到箭靶上的结果
		}
		for(int i=0; i<res.size(); i++)
		{
			int x=res[i].first;
			//x 轴坐标
			int y=res[i].second;
			//y 轴坐标
			int sum=n*(x-1)+y-1 ;
			// 通过计算的到为题目要求的坐标系
			cout <<sum<< " ";
		}
		cout << endl;
		return false;
		// 成功终止
	}
	return true; //继续搜索
	//关于终止还是继续我们交给判定即可
}
bool pd(int x2,int y2) //边界判断
{
	if(flag[x2][y2]==1)
		return 0;
	//已被走过，不能再走，超出边界
	else if(x2<1)
		return 0;
	//从左侧走出方格
	else if(x2>n)
		return 0;
	//从右侧走出方格
	else if(y2<1)
		return 0;
	//从上侧走出方格
	else if(y2>n)
		return 0;
	//从下侧走出方格
	else if(col[x2]<=0)
		return 0;
	//没走到右下角，箭用完了
	else if(rol[y2]<=0)
		return 0;
	//没走到右下角，箭用完了
	else return 1;
	//符合边界条件，可以继续执行搜索
}

void dfs(int x,int y)
{
	if(!check(x,y))
	{
		return ;
		//包含不符合规则的地方，回溯，用于剪枝
	}
	else
	{
		for(int i=0; i<4; i++)
		{
			int xt=dx[i]+x;
			int yt=dy[i]+y;
			if(!pd(xt,yt))
			{
				continue ;
				//不符合要求继续换方向搜索
			}
			else
			{
				//因为要进行位置转移，我们给它起个名字，叫作案现场
				//比如向下移动
				flag[xt][yt]=true;
				col[xt]--;
				rol[yt]--;
				res.push_back({xt,yt});
				dfs(xt,yt);
				//搜索回溯后，因为没有找到正确答案，所以要回复作案现场，返回到搜索之前
				res.pop_back();
				flag[xt][yt]=false;
				col[xt]++;
				rol[yt]++;
			}
		}
	}
}

int main()
{
	cin >> n;
	for(int i=1; i<=n; i++)
		cin >> rol[i];
	for(int i=1; i<=n; i++)
		cin >> col[i];
	flag[1][1]=true;
	col[1]--;
	rol[1]--;
	res.push_back({1,1});
	dfs(1,1);
	return 0;
}
