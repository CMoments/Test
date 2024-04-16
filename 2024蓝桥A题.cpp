#include<bits/stdc++.h>
using namespace std;
int month[] = {0,31,28,31,};
int main()
{
	while(true)
	{
		d++;
		if(闰年)month[2] = 29;
		else month[2] = 28;
		
		if(d > month[m])
		{
			d -= month[m];
			m ++ ;
		}
		if(m > 12)
		{
			m -= 12;
			y++;
		}
		
		if(y == 2024 && m == 4 && d == 13)break;
	}
	
	return 0;
}
