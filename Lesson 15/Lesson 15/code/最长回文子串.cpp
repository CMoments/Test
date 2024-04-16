#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
char s[N];int ans=0,p[N];//s[N]为字符串，p[N]为转变后的每个字符的回文半径
int main()
{ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>s+1;int n=strlen(s+1);
	for(int i=n+n+1;i>=1;i--) s[i]=(i&1)?'#':s[i/2];//逆序遍历，奇数位置放#，偶数位置放原始字符,n+n+1表示原始字符串长度加上所有#的长度
	s[0]='^';s[n+n+2]='$';//看图
	int C=0,R=0;//C表示对称中心下标，R表示当前最右回文区间右端点
	for(int i=1;i<=n+n+1;i++)//manachr算法
	{
		p[i]=i<R?min(p[2*C-i],R-i):1;//若i<R则有对称中心，可以用性质 
		while(s[i+p[i]]==s[i-p[i]]) p[i]++;//当前回文区间往外扩展，看看是否有更大的回文区间
		if(i+p[i]>R) C=i,R=i+p[i];//更新C,R
	}
	for(int i=1;i<=n+n+1;i++) ans=max(ans,p[i]-1);//原始字符串最长回文串=p[i]-1
	cout<<ans;
	
	
	
	
	return 0;
}
