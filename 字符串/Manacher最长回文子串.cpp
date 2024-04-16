#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 9;
char s[N];
int p[N];

int main()
{
	cin >> s + 1;
	int n = strlen(s + 1);
	for(int i = 2 * n + 1;i >= 1;i --)s[i] = (i & 1) ? '#' :s[i >> 1];
	s[0] = '^',s[2*n + 2] = '$';
	
	int C = 0,R = 0;
	for(int i = 1;i <= 2 * n + 1;i ++)
	{
		p[i] = i < R ? min(R - i,p[2 * C - i]) : 1;
		while(s[i + p[i]] == s[i - p[i]])p[i] ++;
		if(i + p[i] > R)C = i,R = i + p[i];
	}
	int ans = 0;
	for(int i = 1;i <= 2 * n + 1;i ++)ans = max(ans,p[i] - 1);
	cout << ans << endl;
	return 0;
}
