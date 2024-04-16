#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

char c[20];
LL ans=0;
//n:1号操作剩余次数  m:2号操作剩余次数
int n,m;
void dfs(int i,LL v){
	int x=c[i]-'0';
	if(c[i]){
		//应该使用的操作次数
		int t=min(n,9-x);
		n-=t;
		dfs(i+1,v*10+x+t);
		//回溯
		n+=t;
		//考虑操作2是否能够使用
		if(m>x){
			m-=x+1;
			dfs(i+1,v*10+9);
			//回溯
			m+=x+1;
		}
	}else{
		//答案取max
		ans=max(ans,v);
	}
}
int main()
{
	scanf("%s%d%d",c,&n,&m);
	dfs(0,0);
	printf("%lld\n",ans);
	return 0;
}
