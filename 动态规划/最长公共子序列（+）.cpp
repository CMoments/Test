#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 9;
int n,m,a[N],b[N],dp[N][N];
int main(){
	int n,m;cin >> n >> m;
	for(int i = 1;i <= n;i ++)cin >> a[i];
	for(int i = 1;i <= m;i ++)cin >> b[i];
	
	for(int i = 1;i <= n;i ++)
	{
		for(int j = 1;j <= m;j ++)
		{
			if(a[i] == b[j])dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);
		}
	}
	
	vector<int> v;
	int x = n,y = m;
	while(x && y)
	{
		if(a[x] == b[y])
		{
			v.push_back(a[x]);
			x--,y--;
		}else if(dp[x - 1][y] > dp[x][y - 1])x--;
		else y --;
	}
	reverse(v.begin(),v.end());
	for(const auto & i: v)cout << i << ' ';
	
	return 0;
}
