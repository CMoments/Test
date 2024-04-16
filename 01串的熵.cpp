#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n = 23333333;
	for(int i = 1;i < n;++i)
	{
		double a = i * 1.0 / n;
		double b = (n - i) * 1.0 / n;
		double res = 0;
		res -= a * log2(a) * i + b * log2(b) * (n - i);
		if(fabs(res - 11625907.5798) < 0.0001)
		{
			cout << i << endl;
			break;
		}
	}	
	return 0;
}
