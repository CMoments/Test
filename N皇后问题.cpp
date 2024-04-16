#include<iostream>
#include<cstdio>
using namespace std;

int x[15] = {0};
int sum,n;

int PD(int k)
{
	for(int i = 1;i < k;++ i)
	{
		if(abs(k - i) == abs(x[k] - x[i]))
			return 0;
		else if(x[k] == x[i])
			return 0;
	}
	
	return 1;
}

bool check(int a)
{
	if(a > n)
		sum ++ ;
	else 
		return 0;
	
	return 1;
}

void DFS(int a)
{
	if(check(a))
		return ;
	else
		for(int i = 1;i <= n;++ i)
	{
		x[a] = i;
		
		if(PD(a))
			DFS(a + 1);
		else continue;
	}
	
	
}


int main()
{
	cin >> n;
	DFS(1);
	cout << sum << endl;
	return 0;
}
