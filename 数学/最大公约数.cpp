#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
	return b == 0 ? a :gcd(b,a % b);
}
int lcm(int a,int b)
{
	return a / gcd(a,b) * b;  //先除再乘，避免溢出
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T;cin >> T;
	while(T --)
	{
		int a,b;cin >> a >> b;
		cout << gcd(a,b) << endl;
	}
	return 0;
}
