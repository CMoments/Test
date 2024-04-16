#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
const ll p = 1e9 + 7;
const int inf = 1e9,N = 1e3 + 3;

ll f(int n){

	if(n <= 2)return 1;
	return (f(n - 1) + f(n - 2)) % p;
}
int main()
{
	int n; cin >> n;
	for(int i = 1;i <= n; ++ i)cout << f(i) << endl;
	return 0;
}
