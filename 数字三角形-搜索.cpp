#include<bits/stdc++.h>
using namespace std;
const int maxn = 110;
int n;
int maxnum;
int note[maxn] = {0},left = 0,right1 = 0,pos = 1;

int a[maxn][maxn];

void dfs(int x,int left,int right)
{
	if(x == n)
	{
		if(abs(left - right) > 1){
			return ;
		}
		note[x] = a[x][1 + right];
		int sum = 0;
		for(int i = 1;i <= n;++ i)
		{
			sum += note[i];
		}
		if(sum > maxnum)maxnum = sum;
		return ;
	}
	note[x] = a[x][1 + right];
	dfs(x + 1,left + 1,right);
	dfs(x + 1,left,right + 1);
}


int main()
{
	cin >> n;
	for(int i = 1;i <= n;++ i)
	{
		for(int j = 1;j <= i;++ j)
		{
			cin >> a[i][j];
		}
	}
	dfs(1,0,0);
	cout << maxnum << endl;
	
	return 0;
}
