#include<bits/stdc++.h>

using namespace std;
const int MAXN=100010;
int n,k;
int h[MAXN],w[MAXN];

bool pd(int l)
{
	int sum=0;
	for(int i=0; i<n; i++)
	{
		sum+=(h[i]/l)*(w[i]/l);
		if(sum>=k)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	cin>>n>>k;
	for(int i=0; i<n; i++)
		cin>>h[i]>>w[i];
	
	//找到二分查找的上界
	int high=0;
	
	for(int i=0; i<n; i++)
	{
		high=max(high,h[i]);
		high=max(high,w[i]);
	}
	// 二分下届由题意可得至少为1
	int low=1;
	
	// 由于本题目就是求符合要求的Mid 值所以要将mid定义在二分查找外边
	int mid=0;
	while(low<high)
	{
		
		mid = (low + high+1) / 2;
		if(pd(mid))
			low=mid;
		else
			high = mid - 1;
		
		//        cout<<low<<" "<<high<<endl;
	}
	
	//因为low=high所以输出哪一个都一样
	cout<<low;
	return 0;
}
