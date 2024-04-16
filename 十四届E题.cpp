#include<bits/stdc++.h>
using namespace std;

const int N = 200010;
int n,c[N],ans;
vector<int> g[N];
unordered_map<int,int>cnt[N],sum[N];

void dfs(int u){
	cnt[u][c[u]] = sum[u][1] = 1;
	for( auto &v : g[u])
	{
		dfs(v);
		for(auto &it : cnt[v]){
			int x = it.first,y = it.second;
			if( cnt[u].count(x) && !--sum[u][cnt[u][x]])sum[u].erase(cnt[u][x]);
			++sum[u][cnt[u][x]+=y];
		}
	}
	ans += sum[u].size() == 1;
}
int main()
{
	cin >> n;
	for(int i = 1,x;i <= n; ++ i)
	{
		scanf("%d%d",c + i,&x);
		g[x].emplace_back(i);
	}
	dfs(1);
	cout << ans;
	return 0;
}
