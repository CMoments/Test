#include<bits/stdc++.h>
using namespace std;

int a[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14};
void print_subset(int n){
	
	for(int i = 0;i < (1 << n);++ i)
	{
		for(int j = 0;j < n;++ j)
		{
			if(i & (1<<j)){
				cout << a[j] << " ";
			}
		}
		cout << endl;
	}
}
int main()
{
	int n = 3;
	print_subset(n);
}
