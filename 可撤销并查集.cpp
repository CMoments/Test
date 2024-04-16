#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
int pre[N];

int root(int x){return pre[x] = (pre[x] == x ? x : root(pre[x]));}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i ++)pre[i] = i;
	
	while(m --)
	{
		int op,x,y;cin >> op >> x >> y;
		if(op == 1)
		{
			pre[root(x)] = root(y);
		}else
		{
			cout << (root(x) == root(y) ? "YES" :"NO") << endl;
		}
	}
	return 0;
}


