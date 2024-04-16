#include <stdio.h>

// 定义矩阵结构体
typedef struct {
	long long mat[2][2];
} Matrix;

// 矩阵乘法
Matrix multiply(Matrix a, Matrix b, long long int mod) {
	Matrix res;
	res.mat[0][0] = (a.mat[0][0] * b.mat[0][0] + a.mat[0][1] * b.mat[1][0]) % mod;
	res.mat[0][1] = (a.mat[0][0] * b.mat[0][1] + a.mat[0][1] * b.mat[1][1]) % mod;
	res.mat[1][0] = (a.mat[1][0] * b.mat[0][0] + a.mat[1][1] * b.mat[1][0]) % mod;
	res.mat[1][1] = (a.mat[1][0] * b.mat[0][1] + a.mat[1][1] * b.mat[1][1]) % mod;
	return res;
}

// 矩阵快速幂
Matrix matrixPower(Matrix base, long long exp, long long int mod) {
	Matrix res = {1, 0, 0, 1}; // 单位矩阵
	while (exp > 0) {
		if (exp % 2 == 1)
			res = multiply(res, base, mod);
		base = multiply(base, base, mod);
		exp /= 2;
	}
	return res;
}

// 求斐波那契数列第n项（取模）
long long f(long long int n, long long int mod) {
	Matrix base = {1, 1, 1, 0};
	Matrix res = matrixPower(base, n - 1, mod); // 第n-1次幂
	return res.mat[0][0];
}

int main() {
	int n;
	long long int mod=1e9+7;
	scanf("%d", &n);
	long long int a[n];
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=0;i<n;i++){
		printf("%lld\n",f(a[i],mod));
	}
	return 0;
}
