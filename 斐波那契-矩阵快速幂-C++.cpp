#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int q = 1e9+7;
//矩阵快速幂模板题，注意矩阵运算写法 
struct Matrix {
	std::array<std::array<ll, 2>, 2> a;
	
	Matrix() : a{} {}
	
	Matrix operator*(const Matrix &A) const {
		Matrix ret;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				for (int k = 0; k < 2; k++) {
					ret.a[i][j] += a[i][k] * A.a[k][j];
					//取模操作 (放在这里很好)
					ret.a[i][j] %= q;
				}
			}
		}
		return ret;
	}
	
	Matrix qpow(ll n) const {
		Matrix ret, mul = *this;
		for (int i = 0; i < 2; i++)ret.a[i][i] = 1;
		while (n > 0) {
			if (n & 1)ret = ret * mul;
			mul = mul * mul, n >>= 1;
		}
		return ret;
	}
};


void solve(){
	ll n;
	cin>>n;
	Matrix A,F;
	F.a[0][0] = 1,F.a[1][0] = 0;
	A.a[0][0] = 1,A.a[0][1] = 1,A.a[1][0] = 1,A.a[1][1] = 0;
	A = A.qpow(n);
	//cout<< A.a[0][0]<<' '<<A.a[0][1]<<' '<<A.a[1][0]<<' '<<A.a[1][1];
	A = A*F;
	cout << A.a[1][0] % q <<endl;
}


int main(){
	int T;cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
