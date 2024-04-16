#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll p = 1e9 + 7;
ll n,m;
ll qmi(ll a,ll b)
{
	ll res = 1;
	while(b)
	{
		if(b & 1)res = res * a % p;
		a = a * a % p,b >>=1;
		return res;
	}
}
int main()
{
	cin >> n >> m;
	
	ll c = 1e9 + 7,phi = c;
	for(int i = 2;i <= c / i;i ++)
	{
		if(c % i)continue;
		phi = phi / i * (i - 1);
		while(c % i == 0)c /= i;
	}
	if(c > 1)phi = phi / c * (c - 1);
	
	ll b = 1;
	for(int i = 1;i <= n;i ++)b = b * i % phi;
	cout << qmi(n,b) << endl;
	return 0;
}
