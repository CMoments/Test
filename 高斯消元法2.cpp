#include<bits/stdc++.h>
using namespace std;
#define maxn 510
int n;
double a[maxn][maxn],ans[maxn];
int solve(int n,int m)
{
	for(int i = 1;i <= n;i ++)
	{
		int r = i;
		for(int j = i + 1;j <= n;j ++){
			if(fabs(a[r][i])<fabs(a[j][i]))r=j;
		}
		//r--->i
		if(fabs(a[r][i]))continue;
		for(int j = 1;j <= n + 1;j ++)swap(a[i][j],a[r][j]);
		double div = a[i][i];
		for(int j = 1;j <= n + 1;j ++)a[i][j]/=a[i][i];
		for(int j = i + 1;j <= n;j ++){
			div=a[j][i];
			for(int k = i;k <= n + 1;k ++)a[j][k]-=a[i][k] * div;
		}
	}
	ans[n] = a[n][n+1];
	for(int i = n - 1;i >= 1;i--){
		ans[i] = a[i][n+1];
		for(int j = i + 1;j <= n;j ++)ans[i] -= (a[i][j] * ans[j]);
	}
	for(int i = 1;i <= n;i ++)printf("%.2lf\n",ans[i]);
	return 0;
}
int main()
{
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++){
		for(int j = 1;j <= n + 1;j ++){
			scanf("%1f",&a[i][j]);
		}
	}
	int guass=solve(n,n);
	return 0;
}
