//计算斐波那契数列有很多种方法,而当阶数N很大时,矩阵快速幂算法是最佳的 
#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

const int mod=1e9+7;

class Matrix//矩阵类 
{
public:
	int row,col;//row为矩阵的行数,col为矩阵的列数 
	ull matrix[5][5];//矩阵 
	Matrix(int r=2,int c=2,int tag=0)//构造函数 
	{
		row=r;
		col=c;
		memset(matrix,0,sizeof(matrix));
		if(tag)//若传入tag为非0,则初始化为单位矩阵 
		{
			for(int i=0;i<min(r,c);i++)
			{
				matrix[i][i]=1;//对角线元素初始化为1 
			}    
		}    
	}        
};

Matrix operator *(Matrix m1,Matrix m2)//矩阵乘法,返回结果矩阵 
{
	Matrix ans;//构造一个2行2列的矩阵,初始化均为0 
	memset(ans.matrix,0,sizeof(ans.matrix));
	for(int i=0;i<m1.row;i++)//遍历第一个矩阵的每一行 
	{
		for(int j=0;j<m2.col;j++)//遍历第二个矩阵的每一列 
		{
			for(int k=0;k<m1.col;k++)//第一个矩阵的行与第二个矩阵的列一一对应相乘再相加 
			{
				ull tmp=m1.matrix[i][k]*m2.matrix[k][j]%mod; 
				ans.matrix[i][j]=(ans.matrix[i][j]+tmp)%mod;
			}
		}
	}
	return ans;
}

Matrix matrix_mul(Matrix m,ull power)//矩阵快速幂,求解矩阵m的power次幂 
//原理与普通快速幂相同,重载了矩阵相乘的函数之后可直接套用普通快速幂算法 
{
	Matrix ans(2,2,1);//初始化为单位矩阵 
	while(power)
	{    
		if(power&1)
		{
			ans=ans*m;
			power--;
		}
		power=power>>1;
		m=m*m;
	}
	return ans;
}

ull F(Matrix M,ull n)//计算N阶斐波那契数列 
{
	Matrix ans=matrix_mul(M,n);//计算矩阵M的N次幂 
	return ans.matrix[1][0];//取其右下角元素即为最终答案 
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	Matrix M(2,2,0);
	//构造一个矩阵为{ {1,1} , {1,0} } 
	//N阶斐波那契数列等于该矩阵的N次幂的右上角/左下角元素 
	M.matrix[0][0]=M.matrix[0][1]=1;
	M.matrix[1][0]=1;
	M.matrix[1][1]=0;
	while(T--)
	{
		ull N;
		cin>>N;
		cout<<F(M,N)<<endl;
	}
	return 0;
}
