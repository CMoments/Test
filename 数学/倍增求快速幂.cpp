#include<bits/stdc++.h>
using namespace std;

using ll = long long;
int qmi(ll a,ll b,ll p)
{
	ll res = 1;
	while(b)
	{
		if(b&1)res = res * a % p;
		a = a * a % p,b >>= 1;
	}
	return res;
}

int main()
{
	int t;cin >> t;
	for(int i  =1;i <= t;i ++)
	{
		ll m,n,p;
		cin >> m >> n >> p;
		cout << qmi(m,n,p)<< endl;
	}
	
	return 0;
}
