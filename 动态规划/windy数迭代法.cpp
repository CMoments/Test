#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int dp[20][20];
//dp[i][j]表示长度为i的数字,最高位是j的小明数的个数
int dig[20];//存储一个数字的每一位,如123 -> 1 2 3

ll solve(int x)
{
	memset(dig,0,sizeof(dig)); 
	int cnt=0;//cnt为x的长度 
	while(x)//拆分x,如123 -> 1 2 3 
	{
		dig[++cnt]=x%10;
		x=x/10;
	}
	
	ll ans=0;
	for(int i=1;i<cnt;i++)//对于所有长度小于cnt的数字,放心累加
	{
		for(int j=1;j<=9;j++)//枚举最高位所有可能的数字0~9
		{
			ans+=dp[i][j];    
		}    
	} 
	
	for(int i=1;i<dig[cnt];i++)//长度等于cnt,但是最高位比x的最高位小
	{
		ans+=dp[cnt][i];
	}
	
	for(int i=cnt-1;i>=1;i--)//枚举当前填到哪一位
	{
		for(int j=0;j<=dig[i]-1;j++)//枚举第一位填什么,从0到当前次高位减1
		{
			if(abs(j-dig[i+1])>=2)//次高位与最高位的差大于等于2
			{
				ans+=dp[i][j];
			}
		}
		if(abs(dig[i+1]-dig[i])<2)break;//不能填这个数字
	}
	return ans;
}

int main()
{
	int L,R;
	cin>>L>>R;
	memset(dp,0,sizeof(dp));
	for(int i=0;i<=9;i++)dp[1][i]=1;//初始化,长度为1,一定有一个
	
	for(int i=2;i<=10;i++)//枚举当前数字的位数 
	{
		for(int j=0;j<=9;j++)//当前数字的最高位 
		{
			for(int k=0;k<=9;k++)//枚举长度为i-1的数字(上一个状态)的最高位 
			{
				if(abs(j-k)>=2)//最高位差值的绝对值小于等于K,满足条件 
				{
					//可以从上一个状态转移而来 
					dp[i][j] += dp[i-1][k];//累加小明数的数量 
				}
			}
		}
	}
	
	ll ans=solve(R)-solve(L-1);
	cout<<ans<<endl;    
	
	return 0;
}
