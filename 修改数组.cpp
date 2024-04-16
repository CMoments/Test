#include<bits/stdc++.h>
using namespace std;
#define Maxn 000000

int fa[Maxn + 1];

void init()
{
	for(int i = 0;i <= Maxn;++ i){
		
		fa[i] = i;
	}
}
int find(int x)
{
	if(x == fa[x]){
		return x;
	}else 
	{
		fa[x] = find(fa[x]);
		
		return fa[x];
	}
}

void merge(int i ,int j){
	
	fa[find(i)] = find(j);
}

int main()
{
	init();
	
	int n;
	cin >> n;
	for(int i = 0;i < n;++ i)
	{
		int t;
		cin >> t;
		t = find(t);
		cout << t << " ";
		merge(t,t + 1);
	}
	
	
	
	return 0;
}
