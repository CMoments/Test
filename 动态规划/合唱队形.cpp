#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
const int N = 150;
int a[N],dpl[N],dpr[N];

int main()
{
	int n;cin >> n;
	for(int i = 1;i <= n; ++i)cin >> a[i];
	for(int i = 1;i <= n;i ++)
	{
		dpl[i] = 1;
		for(int j = 1;j < i;j ++)if(a[i] > a[j])dpl[i] = max(dpl[i],dpl[j] + 1);
	}
	for(int i = n;i >= 1;--i)
	{
		dpr[i] = 1;
		for(int j = i + 1;j <= n;j ++)if(a[i] > a[j])dpr[i] = max(dpr[i],dpr[j] + 1);
	}
	
	int ans = 0;
	for(int i = 1;i <= n;i ++)ans = max(ans,(dpl[i] + dpr[i] - 1));
	
	cout << n-ans << endl;
	return 0;
}
