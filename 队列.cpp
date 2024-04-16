#include<iostream>
using namespace std;
const int N = 2e3 + 9;
int q[N],hh = 1,tt = 0;

int main()
{
	int m,n;cin >> m >> n;
	int ans = 0;
	for(int i = 1;i <= n;i ++)
	{
		int x;cin >> x;
		bool tag = false;
		for(int j = hh;j <= tt;++j)if(q[j] == x)tag = true;
		if(tag)continue;
		
		if(tt - hh + 1 == m)hh ++;
		q[++ tt] = x;
		ans ++;
	}
	cout << ans << endl;
	return 0;
}
