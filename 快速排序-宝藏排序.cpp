#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;

int a[N];

int partition(int a[],int l ,int r)
{
	int pivot = a[r],i = 1,j = r;
	while(i < j)
	{
		while(i < j && a[i] <= pivot)i ++;
		while(i < j && a[j] >= pivot)j--;
		if(i < j)swap(a[i],a[j]);
		else swap(a[i],a[r]);
	}
	return i;
}

void QuickSort(int a[],int l,int r)
{
	if(l < r)
	{
		int mid = partition(a,l,r);
		QuickSort(a,l,mid - 1);
		QuickSort(a,mid + 1,r);
	}
}


int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin >> n;
	for(int i = 1;i <= n; ++ i)cin >> a[i];	
	
	QuickSort(a,1,n);
	for(int i = 1;i <= n; ++ i)cout << a[i] << " \n"[i == n];
	return 0;
}
