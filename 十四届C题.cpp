#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL get_sum(LL x)
{
	return x/4 + (x + 1) / 2;
}
int main()
{
	LL l,r;
	cin >> l >> r;
	
	cout << get_sum(r) - get_sum(l - 1);
	return 0;
}
