#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 9;
vector<int> g[N];

int siz[N];
void dfs(int x,int p)
{
	siz[x] = 0;
	for(const auto &y: g[x])
	{
		if(y == p)continue;
		dfs(y,x);
		siz[x] += siz[y] + 1;
		
	}
}

struct Node
{
	int id,siz;
	bool operator < (const Node &u)const
	{
		return siz == u.siz ? id < u.id : siz > u.siz;
	}
};


int main()
{
	int n,m;cin >> n >> m;
	
	for(int i = 1;i < n;++i)
	{
		int x,y;cin >> x >> y;
		g[y].push_back(x);
	}
	dfs(1,0);
	vector<Node> v;
	for(int i =1 ;i <= n;++i)v.push_back({i,siz[i]});
	sort(v.begin(),v.end());
	for(int i = 0;i < n;++i)if(v[i].id == m)cout << i + 1 << endl;
	
	
	return 0;
}
