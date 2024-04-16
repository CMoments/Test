#include<bits/stdc++.h>
#include<vector>

using namespace std;
int a[10];
vector <int> ans[10];
int main()
{
	for(int i = 0;i < 6; ++ i)
	{
		char c;
		cin >> c ;
		if(c == 'A'){
			a[i] = 1;
		}else if(c == 'J'){
			a[i] = 11;
		}else if(c == 'Q'){
			a[i] = 12;
		}else if(c == 'K'){
			a[i] = 13;
		}else 
		{
			a[i] = (c - '0');
		}
	}
	ans[0].push_back(a[0]);
	for(int i = 1;i <= 5;++ i)
	{
		for(int j = 0;j < ans[i - 1].size();++ j)
		{
			ans[i].push_back(ans[i-1][j] + a[i]);
			ans[i].push_back(ans[i-1][j] - a[i]);
			ans[i].push_back(ans[i-1][j] * a[i]);
			ans[i].push_back(ans[i-1][j] / a[i]);
		}
	}
	int flag = 0;
	for(int i = 0;i < ans[5].size(); ++ i)
	{
		if(ans[5][i] == 42)
		{
			flag = 1;
			break;
		}
	}
	if(flag == 1)
		cout << "YES" << endl;
	else 
		cout << "NO" << endl;
	
	return 0;
}
