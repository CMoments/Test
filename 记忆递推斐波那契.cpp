#include <iostream>
using namespace std;
int F[35];

void init()
{
	F[0]=0;
	
	F[1]=1;
	
	for(int i=2;i<=30;i++)
	{
		F[i]=F[i-1]+F[i-2];
	}
}
int main()
{
	
	int m; //m次查询
	int n; //第几个数
	init();
	
	cin>>m;
	
	while(m>0){
		m-=1;
		cin>>n;
		cout<<F[n]<<endl;
	}
}
/*
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
  */
