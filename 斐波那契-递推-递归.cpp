#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	int x = 0;
	int y = 1;
	int ans;
	
	cin >> n;
	if(n == 0)ans = 0;
	
	else if(n = 1)ans = 1;
	else {
		for(int i = 2;i <= n;++ i)
		{
			ans = x + y;
			x = y;
			y = ans;
		}
	}
	
	cout << ans << endl;
	return 0;
}
/*
  
  #include <iostream>
  using namespace std;
  
	  int fn(int n)
  {
	  //递归出口1
	  if(n==0)
	  return 0;
  
  //递归出口2
	  else if(n==1 )
	  return 1;
  
	  else
	  return fn(n-1)+fn(n-2); //递归关系式
  }
  
  
  int main()
  {
	  
	  int n; //第几个数
	  int ans;
  
	  cin>>n;
  
	  ans=fn(n);
  
	  cout<<ans<<endl;
  }
 */
