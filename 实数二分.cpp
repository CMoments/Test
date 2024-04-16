#include <cstdio>
#include <iostream>
#include<iomanip> //用于浮点数输出
using namespace std;

double n,l,r,mid;
double eps=1e-8;

bool pd(double a,int m)
{
	double c=1;
	while(m>0)
	{
		c=c*a;
		m--;
	}
	if(c>=n)
		return true;
	else
		return false;
}

int main()
{
	int m;
	cin>>n>>m;
	//设置二分边界
	l=0,r=n;
	//实数二分
	while (l + eps < r)
	{
		double mid = (l + r) / 2;
		if (pd(mid,m))
			r = mid;
		else
			l = mid;
	}
	
	cout<<fixed<<setprecision(7)<<l;
	//一般使用print
	//printf("%x.yf",n)
	//其中X是固定整数长度，小数点前的整数位数不够，会在前面补0
	//y是保留小数位数，不够补零
	//printf("%.7f",l);
	return 0;
}
