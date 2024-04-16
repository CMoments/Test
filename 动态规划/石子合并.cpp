#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000
int main(){
	int n,a[MAXN],f[MAXN][MAXN];
    cin >> n;
	memset(f,127,sizeof(f));
	for(int i = 1;i <= n;i ++) {
		cin >> a[i];
		f[i][i] = 0;
		a[i] += a[i - 1];
	}
	for(int len = 2;len <= n;len ++) {
		for(int i = 1;i <= n - len + 1;i ++) {
			int j = i + len - 1;
			for(int k = i;k < j;k ++) {
				f[i][j] = min(f[i][j],f[i][k] + f[k + 1][j] + a[j] - a[i - 1]);
			}
		}
	}
	cout << f[1][n] << endl;
	return 0;
}
