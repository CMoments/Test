//本题的难点仍在于状态转移方程的设计与列写
//由于两台机器完全相同，若总时间为sum，其中一台洗车时间为i，则另一台洗车时间为sum-i
//i与sum-i中的较大值即为最终答案
//故本题可以只考虑其中一台机器，枚举其所有洗车方案(可能花费的洗车时间)并使用动态规划验证该方案是否可行
//最终遍历该台机器所有可行的洗车方案，计算并比较出最终的洗车时间 
//注：本题有一种错误解法，即把数组排序以后令两台机器分别从头和尾开始往中间遍历洗车
//这种解法是基于贪心思想的，但它并不能保证两台机器的洗车时间尽可能的接近，因此无法得出正确答案
//事实上在允许的时间复杂度内，本题并不存在直接找出最佳洗车方案的算法，
//只能使用动态规划来验证每一种洗车方案,然后比较得出最终答案 
#include <bits/stdc++.h>

using namespace std;

int Time[109];
bool dp[109][10009];
//dp[i][j]表示只考虑前i辆车(每辆车可能洗或不洗)，能否使总洗车时间为j，若能则为true 

int main()
{
	int N;
	int sum=0;
	int ans=1e9;
	cin>>N;
	for(int i=1;i<=N;i++)
	{
		cin>>Time[i];
		sum=sum+Time[i];//计算总洗车时间 
	}
	
	for(int i=0;i<=N;i++)dp[i][0]=true;//初始化，若该机器总洗车时间为0，必然能做到 
	
	for(int i=1;i<=N;i++)//遍历每一种可能的洗车方案，依次考虑前1~N辆车 
	{
		for(int j=0;j<=sum;j++)//对于每一种洗车方案，遍历该机器所有可能的洗车时间，可能花0~sum分钟 
		{
			//若洗前i-1辆车的时间为j-Time[i],则洗前i辆车的时间可以是j(洗第i辆车)
			//若洗前i-1辆车的时间为j，则洗前i辆车的时间也可以是j(不洗第i辆车)
			//两种情况满足其一，dp[i][j]即为true
			//此处注意j-Time[i]要大于等于0，故分开写(合在一起写会有一个测试点错误) 
			dp[i][j]=dp[i-1][j];
			if(j>=Time[i])dp[i][j]=dp[i][j] | dp[ i - 1 ][ j - Time[i] ];    
		}    
	} 
	
	for(int i=1;i<=sum;i++)//遍历其中一台机器所有可能的洗车时间1~sum 
	{
		if(dp[N][i])//若对于前N辆车，该机器洗车时间可以是i 
		{
			int tmp=max(sum-i,i);//则对于该洗车方案，两台机器洗车完成的时间是sum-i和i之间的较大值 
			if(tmp<ans)ans=tmp;//比较得出所有洗车方案所花时间的最小值 
		}
	}
	cout<<ans<<endl;
	return 0;
}
