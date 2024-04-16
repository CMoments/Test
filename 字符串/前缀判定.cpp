#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 9;


int nex[N][26];
int cnt[N];
int idx = 2;
void insert(char s[])
{
	int x = 1;
	for(int i = 0;s[i];i ++)
	{
		//判断x是否存在s[i]这条边
		if(!nex[x][s[i] - 'a'])nex[x][s[i] - 'a'] = idx++;
		x = nex[x][s[i] - 'a'];
	}
	cnt[x] ++;
}
bool check(char s[])
{
	int x = 1;
	for(int i = 0;s[i];i ++)x = nex[x][s[i] - 'a'];
	return x;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;cin >> n >> m;
	for(int i = 1;i <= n;i ++)
	{
		char s[N];cin >> s ;
		insert(s);
	}
	for(int i = 1;i <= m;i ++)
	{
		char s[N];cin >> s;
		cout << (check(s) ? "Y" : "N") << endl;
	}
	return 0;
}
