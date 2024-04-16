#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
const ll p = 1e9 + 7;
ll qmi(ll a,ll b)
{
	ll res = 1;
	while(b)
	{
		if(b & 1)res = res * a % p;	
		a = a * a % p,b >>= 1;
	}
	return res;
}
ll inv(ll x)
{
	return qmi(x,p-2);
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
		int _;cin >> _;
		while(_--)
		{
			ll n;cin >> n;
			cout << inv(n) << endl;
		}
	return 0;
}
