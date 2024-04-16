#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int a[N];
int b[N];
void MergeSort(int a[],int l ,int r)
{
	if(l == r)return ;
	int mid = (l + r) / 2;
	MergeSort(a,l,mid);
	MergeSort(a,mid + 1,r);
	
	int pb = l,pl =  l,pr = mid + 1;
	while(pl <= mid || pr <= r)
	{
		if(pl > mid)b[pb++] = a[pr++];
		else if(pr > r)b[pb++] = a[pl ++];
		else{
			if(a[pl] < a[pr])b[pb ++] = a[pl ++];
			else b[pb ++] = a[pr ++];
		}
	}
	for(int i = l;i <= r;++ i)a[i] = b[i];
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin >> n;
	for(int i = 1;i <= n;++ i)cin >> a[i];
	
	MergeSort(a,1,n);
	for(int i = 1;i <= n;++ i)cout << a[i] << " \n"[i == n];
	return 0;
}
