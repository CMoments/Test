#include<bits/stdc++.h>
using namespace std;



const int MAXN = 110;
const int MAXV = 1010;

int N,V;
int w[MAXN],v[MAXN];
int f[MAXN][MAXN];


int main()
{
	cin >> N >> V;
	
	for(int i = 1;i <= N;++ i)
	{
		cin >> w[i] >> v[i];
	}
	
	memset(f,0,sizeof(f));
	
	for(int i = 1;i <= N;++ i)
	{
		for(int j = 0;j <= V;++ j)
		{
			f[i][j] = f[i - 1][j];
			if(j >= w[i])
			{
				f[i][j] = max(f[i][j] , f[i - 1][j - w[i]] + v[i]);
			}
		}
	}
	
	cout << f[N][V] <<endl;
	
	return 0;
}
