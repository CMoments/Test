#include<bits/stdc++.h>
using namespace std;
int a[100];
int cnt = 0;
int ans = 0;
int main()
{
	int l,r;
	cin >> l >> r;
	for(int i = l;i <= r;++ i)
	{
		memset(a,0,sizeof a);
		int ll = i;
		int dd = i;
		cnt = 0;
		while(ll)
		{	
			a[cnt] = ll % 10;
			ll /= 10;
			cnt++;
		}
		for(int k = cnt;k <= 2 * cnt - 1;++ k)
		{
			a[k] = a[k-cnt];
		}
		for(int j = 1;j <= cnt-1;++ j){
			int c = 0;
			int base = 1;
		
			for(int n = 0;n < cnt;++ n)
			{
				c = c + a[n+j]*base;
				base = base * 10;
			//	cout << c << endl;
				if(c > dd &&c <= r )
				{
					ans++;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
