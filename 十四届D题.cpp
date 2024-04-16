/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int sum;
	string s;
	cin >> s;
	for(ll i = 0;i < s.size(); ++i)
	{
		for(ll j = i + 1;j < s.size();++j)
		{
			if(s[i] == s[j])
			{
				int x = i;
				int y = j;
				while(1)
				{
					x ++;
					y --;
					if( x >= y || s[x] < s[y])break;
					if(s[x] > s[y])
					{
						sum ++;
						break;
					}
				}
			}
			if( s[i] > s[j])sum ++;
		}
	}
	
	cout << sum << endl;
	return 0;
}*/
#include<bits/stdc++.h>
const int N = 5e3 + 9;
using namespace std;
int dp[N][N];
void solve()
{
	string s;cin >> s;
	int ans = 0;
	for(int len = 2;len <= s.size(); ++ len)
	{
		for(int l = 0;l + len - 1 < s.size();++l)
		{
			int r = l + len - 1;
			
			if(s[l] > s[r])dp[l][r] = 1;
			else if(s[l] == s[r])dp[l][r] = dp[l + 1][r - 1];
			
			ans += dp[l][r];
		}
	}
	cout << ans << endl;
}
int main()
{
	solve();
	return 0;
}
