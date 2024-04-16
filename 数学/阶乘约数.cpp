#include<bits/stdc++.h>
using namespace std;


/*
  约数
  1.唯一分解定理
  对于一个大于1的整数n，可以将n分解成一些质因数的幂次和。
  2.约数定理
  一个正整数的正约数个数等于他通过唯一分解定理分解出来的所有质因数的次幂+1后的累乘结果
  并且，求阶乘约数的时候
  通过举例可以发现，n!的分解质因子的幂次等于1-n的分解每个数的质因子的幂次的和。
  所以如果求100！的约数个数，就可以将1-100中所有的数分解后幂次相加再相乘*/


int a[105];//存储质因子的幂次

bool fun(int n)
{
	//判断质数
	for(int k = 2;k * k <= n;k++)
	{
		if(n % k == 0)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	//根据唯一分解定理：对于一个大于1的整数n，n可以分解质因数为一些质因子的幂次的和
	//枚举1-100求出质因子
	for(int i = 1;i <= 100;i++)
	{
		//求出质因子
		int t = i;//被除数
		for(int j = 2;j <= i;j++)
		{
			//判断因数
			if(i % j == 0)
			{
				//判断质数
				if(fun(j) == true)
				{
					//求出幂
					
					int temp = 0;//幂次
					while(t % j == 0)
					{
						t /= j;
						temp++;//幂次计数
					}
					//累加次幂
					a[j] += temp;
				}
			}
		}
	}
	long long int cnt = 1;
	//最后根据约数定理
	//一个正整数n的正约数等于分解定理分解的所有质因子的幂次+1的累乘
	for(int i = 1;i <= 100;i++)
	{
		a[i]++;
		cnt *= a[i];
	}
	cout << cnt << endl;
	return 0;
}
