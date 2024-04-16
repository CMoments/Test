#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 100
ll a,b,len,dig[maxn];
ll f[20][20][2][2];

ll dfs(int len,int last,int flag,int zero){
	if(!len)return 1;
	if(f[len][last][flag][zero] != -1)return f[len][last][flag][zero];
	ll res = 0;
	int low,up;
	if(flag == 0)up = 9;
	else up = dig[len];
	if(zero == 1)low = 1;
	else low = 0;
	for(int i = low;i <= up;i ++) {
		if(abs(i - last) < 2)continue;
		res+=dfs(len - 1,i,flag&&(i == up),0);
	}
	f[len][last][flag][zero] = res;
	return res;
}


ll solve(ll x){
	if(x <= 9)return x;
	ll tmp = x;len = 0;
	while(tmp){
		dig[++len] = tmp % 10;
		tmp/=10;
	}
	memset(f,-1,sizeof(f));
	ll ans = 0;
	ans = dfs(len,11,1,1);
	for(int i = len - 1;i >= 1;i --) {
		ans += dfs(i,11,0,1);
	}
	return ans;
}
int main(){
	
	scanf("%lld%lld",&a,&b);
	printf("%lld\n",solve(b)-solve(a-1));
	
	return 0;
}
