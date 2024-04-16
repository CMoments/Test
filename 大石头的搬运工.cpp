#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;

#define x first
#define y second 

typedef long long ll;
pair<int,int>p[N];
ll pre[N],nex[N];

int main()
{
	int n;
	cin >> n;
	for(int i = 1;i <= n;++i)
	{
		cin >> p[i].y >> p[i].x;
	}
	sort(p + 1,p + 1 + n,greater<>());
	
	for(int i = 1;i <= n;++i)cout << p[i].first << " " << p[i].second << endl;
	
	
	return 0;
}
