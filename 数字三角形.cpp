#include<iostream>
using namespace std;

int main()
{
	int n; //n层
	int a[101][101]; //路径矩阵
	cin>>n;
	
	//输入数字三角形的值
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=i; j++)
		{
			
			cin>>a[i][j]; //输入原始数据
			
		}
	}
	
	//递推开始
	
	for (int i=n-1; i>=1; i--)//从最后一层逆推
	{
		for (int j=1; j<=i; j++)
		{
			
			if (a[i+1][j]>=a[i+1][j+1])
				a[i][j]+=a[i+1][j];     //路径选择
			
			else
				a[i][j]+=a[i+1][j+1];
		}
	}
	
	cout<<a[1][1]<<endl;
}
