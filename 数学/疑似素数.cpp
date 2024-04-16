#include<bits/stdc++.h>
using namespace std;

int f(int x)
{
	int res= 0;
	while(x)res += x % 10,x /= 10;
	return res;
}
bool isprime(int n)
{
	if(n < 2)return false;
	for(int i = 2;i <= n/i;i ++)if(n % i == 0)return false;
	return true;
}
int main()
{
	int n;cin >> n;
	int ans = 0;
	for(int i = 1;i <= n;i ++)
	{
		if(isprime(f(i)))ans ++;
	}
	
	return 0;
}
