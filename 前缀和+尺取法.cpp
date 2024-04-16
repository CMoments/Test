#include<bits/stdc++.h>
using namespace std;
int s[550][550];
int main(){
	int n,m,k; cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) {
		int a;   scanf("%d",&a);
		s[i][j] = s[i-1][j] + a;            // s[i][j]：第j列上，第0～i行数字的前缀和
	}
	long long ans=0;
	for(int i1=1;i1<=n;i1++)
		for(int i2=i1;i2<=n;i2++)
			for(int j1=1,j2=1,z=0;j2<=m;j2++){  //尺取法，滑动窗口为[j1,j2]。移动指针j2
		z += s[i2][j2]-s[i1-1][j2];     //第j2列上，i1、i2的区间和。累加得到二维区间和
		while(z>k){                     //若区间和 > k，则移动指针j1
			z -= s[i2][j1]-s[i1-1][j1];
			j1 += 1;                  
		}
		ans += j2-j1+1;         //若j1、j2的区间和 < k，则这里面有j2-j1+1个满足条件
	}
	cout << ans;
	return 0;
}
