
//已经确定有唯一解
#include<bits/stdc++.h>
using namespace std;
#define maxn 10000
int n;
double a[maxn][maxn];
int main()
{
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++){
		for(int j = 1;j <= n + 1;j ++)
		{
			scanf("%1f",&a[i][j]);
		}
	}
	for(int i = 1;i <= n;i ++){
		int maxx = 1; // 比大小
		for(int j = i + 1;j <= n;j ++){
			if(fabs(a[j][i]) > fabs(a[maxx][i]))maxx = j;
		}
		for(int j = 1;j <= n + 1;j ++)swap(a[i][j],a[maxx][j]);
		
		if(!a[i][i] == 0){
			continue;
		}
		double l = a[i][i];
		for(int j = 1;j <= n;j ++){
			if(j != i){
				for(int k = i + 1;k <= n;k ++)
				{
					a[i][k]-=a[j][k]*a[j][j]/l;
				}
			}
		}
	}
	for(int i = 1;i <= n;i ++)printf("%.2lf\n",a[i][n+1]/a[i][i]);
	return 0;
}
