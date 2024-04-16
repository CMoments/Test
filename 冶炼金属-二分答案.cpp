#include<bits/stdc++.h>

#define rep(i, a, b) for(int i = a; i < b; i++)

using namespace std;
const int N = 1e4 + 10;
int n;

int get(int a, int b)
{
	int l = 1, r = 1e9 + 1;
	while(l < r)
	{
		int mid = l + r >> 1;
		if(a / mid <= b)
			r = mid;
		else l = mid + 1;
	}
	return r;
}

int main()
{
	cin >> n;
	
	int minv = 1, maxv = 1e9;
	int a, b;
	rep(i, 0, n)
	{
		scanf("%d%d", &a, &b);
		//对于所有的集合取交集
		minv = max(minv, get(a, b));
		maxv = min(maxv, get(a, b - 1) - 1);
	}
	
	cout << minv << " " << maxv;
	
	return 0;
}

  
  bool check_min(int mid)
  {
  for(int i = 0;i < n;++i)
  {
  if(b[i] < a[i] / mid)
  return false;
  }
  return true;
  }
  bool check_max(int mid)
  {
  for(int i = 0;i < n; ++i)
  if(b[i] > a[i] /mid)
	  return false;
	  return true;
  }
  
  int lmax = 1,rmax = 1e9;
	  while(lmax < rmax)
  {
  int mid = lmax + rmax + 1>> 1;
  if(check_max(mid))
  {
	  lmax = mid;
  }else{
	  rmax = mid - 1;
	}
  }
  int lmin = 1,rmin = 1e9;
  while(lmin < rmin)
  {
	  int mid = lmin + rmin >> 1;
	  if(check_min(mid))
	  rmin = mid;
	  else 
	  lmin  = mid +1;
  }
  

