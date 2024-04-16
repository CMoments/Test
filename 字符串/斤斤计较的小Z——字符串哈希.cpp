/*include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
char s[N],p[N];
int nex[N];
int main()
{ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>p+1;int m=strlen(p+1);//p+1表示从下标1开始
	cin>>s+1;int n=strlen(s+1);
	//得到nex数组
	nex[0]=nex[1]=0;//初始化
	for(int i=2,j=0;i<=m;i++)
	{
		while(j&&p[i]!=p[j+1]) j=nex[j];
		if(p[i]==p[j+1]) j++;
		nex[i]=j;
	}
	int ans=0;
	for(int i=1,j=0;i<=n;i++)//复制上面的，p[i]改为s[i]
	{
		while(j&&s[i]!=p[j+1]) j=nex[j];
		if(s[i]==p[j+1]) j++;
		if(j==m) ans++;//匹配成功后需要做的事
	}
	cout<<ans;
	return 0;
}
  */
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
char s[N],p[N];
typedef unsigned long long ull;
const ull base = 131;
ull h1[N],h2[N],b[N];
ull getHash(ull h[],int l,int r)
{
	return h[r] - h[l - 1] * b[r - l + 1];
}
int main()
{ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>p+1;int m=strlen(p+1);//p+1表示从下标1开始
	cin>>s+1;int n=strlen(s+1);
	
	b[0] = 1;
	for(int i = 1;i <= n;i ++)
	{
		b[i] = b[i - 1] * base;
		h1[i] = h1[i - 1]*base + (int)p[i];
		h2[i] = h2[i - 1]*base + (int)s[i];
	}
	int ans = 0;
	for(int i = 1;i + m - 1 <= n;i ++)
	{
		if(getHash(h1,1,m) == getHash(h2,i,i + m -1))ans ++;
	}
	cout << ans << endl;
	return 0;
}
