#include<bits/stdc++.h>
using namespace std;

#define Maxn 2000000

int fa[Maxn + 1];
int siz[Maxn + 1];

void init()
{
	for(int i = 1;i <= Maxn;++ i)
	{
		fa[i] = i;
		siz[i] = 1;
		//rk[i] = 1;
	}
}

int find(int x)
{
	if(x == fa[x])
	{
		return x;
	}else{
		fa[x] = find(fa[x]);
		return fa[x];
	}
}
void merge(int x,int y)
{
	x = find(x);
	y = find(y);
	
	if(x != y)
	{
		if(siz[x] < siz[y])
			swap(x,y);
		siz[x] += siz[y];
		fa[y] = x;
		
		//按秩合并
		//if(rk[x] > rk[y])swap(x,y);
		//fa[x] = y;
		//if(rk[x] == rk[y])rk[y]++;
	}
}

int n,m,k;

int main()
{
	
	init();
	cin >> n >> m >> k;
	int a,b;
	
	for(int i = 1;i <= k;++ i)
	{
		cin>> a >> b;
		merge(a,b);
	}
	int ans = 0;
	for(int i = 1;i <= n * m;++ i)
	{
		if(fa[i] == i)
		{
			ans ++ ;
		}
	}
	
	cout << ans;
	return 0;
}
