#include<bits/stdc++.h>
using namespace std;
vector<int>f;


int main()
{
	int n;
	cin >> n;
	f.push_back(0);
	f.push_back(1);
	for(int i = 2;i <= n;++ i)
	{
		f.push_back(f[i-1]+f[i-2]);
	}
	for(int i = 1;i <= n;++ i)
	{
		cout << f[i] << endl;
	}
	return 0;
}
