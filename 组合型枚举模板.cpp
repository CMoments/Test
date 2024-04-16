#include<bits/stdc++.h>
using namespace std;
int n;
int m;
vector<int>chosen;
string s[1000];

void calc(int x) {
	if(chosen.size() > m || chosen.size() + (n - x + 1) < m)
		return ;
	if(x == n + 1) {
		for(int i = 0;i < chosen.size();++ i)
			cout << s[chosen[i]] << " ";
		puts("");
		return;
	}
	chosen.push_back(x);
	calc(x + 1);
	chosen.pop_back(); //消除痕迹
	calc(x + 1);
}
int main()
{
	cin >> n >> m;
	for(int i = 1;i <= n;++ i)
	{
		cin >> s[i];
	}
	calc(1);
	return 0;
}
