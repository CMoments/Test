#include<iostream>
using namespace std;
int ans = 0;
int main()
{
	int a[9];
	for(int i = 10;i < 100000000;++i)
	{
		int temp = i;
		int index = 0;
		while(temp){
			index ++;
			a[index] = temp % 10;
			temp /= 10;
		}
		if(index & 1)continue;
		int sum1 = 0,sum2 = 0;
		for(int i = 1;i <= index / 2; ++ i)
		{
			sum1 += a[i];
			sum2 += a[index - i + 1];
		}
		if(sum1 == sum2)ans ++;
		
	}
	cout << ans << endl;
	return 0;
}
