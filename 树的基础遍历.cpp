#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
int ls[N],rs[N];

void dfs1(int x)
{
	cout << x << ' ';
	if(ls[x])dfs1(ls[x]);
	if(rs[x])dfs1(rs[x]);
}
//中序遍历
void dfs2(int x)
{
	if(ls[x])dfs2(ls[x]);
	cout << x << ' ';
	if(rs[x])dfs2(rs[x]);
}
//后序遍历
void dfs3(int x)
{
	if(ls[x])dfs3(ls[x]);
	if(rs[x])dfs3(rs[x]);
	cout << x << ' ';
}
//层序遍历
void bfs()
{
	queue<int>q;
	q.push(1);
	while(q.size())
	{
		int x = q.front();
		q.pop();
		cout << x << ' ';
		if(ls[x])q.push(x);
		if(rs[x])q.push(x);
	}
}
int main()
{
	int n;cin >> n;
	for(int i = 1;i <= n;++ i)cin >> ls[i] >> rs[i];
	dfs1(1);
	
	return 0;
}
