#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 105,M = 1010;
ll dp[N][M];

int main()
{
	int n,V;cin >> n >> V;
	
	for(int i = 1;i <= n;i ++)
	{
		ll w,v;cin >> w >> v;
		for(int j = 0;j <= V;j ++)
		{
			if(j >= w)dp[i][j] = max(dp[i-1][j],dp[i-1][j-w]+v);
		    else dp[i][j] = dp[i - 1][j];
		}
		
	}
	
	cout << dp[n][V] << endl;
	
	return 0;
}
/*
  #include<bits/stdc++.h>
  using namespace std;
  
  using ll = long long;
  const int N = 105,M = 1010;
  ll dp[M];
  
  int main()
  {
  int n,V;cin >> n >> V;
  
  for(int i = 1;i <= n;i ++)
  {
  ll w,v;cin >> w >> v;
  for(int j = V;j >= w;j ++)
  {
  dp[j] = max(dp[j],dp[j - w] + v);
  }
  
  }
  
  cout << dp[V] << endl;
  
  return 0;
  }
  */
