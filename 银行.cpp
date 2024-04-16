#include<bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int m;cin  >> m;
	queue<string> V,N;
	while(m--)
	{
		string op;cin >> op;
		if(op == "IN"){
			string name,q;cin >> name >> q;
			if(q == "V")V.push(name);
			else N.push(name);
		}else{
			string q;cin>> q;
			if(q=="V")
			{
				V.pop();
			}else{
				N.pop();
			}
			
		}
	}
	
	while(V.size())
	{
		cout << V.front() <<'\n';
		V.pop();
	}
	
	while(N.size())
	{
		cout << N.front() <<'\n';
		N.pop();
	}
	return 0;
}
