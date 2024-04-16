#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int mod=1e9+7;
using vvl=vector<vector<ll>>;
ll n;

vvl operator*(const vvl &a,const vvl &b){
	vvl ans(2,vector<ll>(2));
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			for(int k=0;k<2;k++){
				ans[i][j]=(ans[i][j]+a[i][k]*b[k][j]%mod)%mod;
			}
		}
	}
	return ans;
}

ll solve(){
	cin>>n;
	vvl mat1={{0,1},{1,1}},matans={{1,0},{0,1}};
	while(n){
		if(n&1)matans=matans*mat1;
		mat1=mat1*mat1;n>>=(ll)1;
	}
	return matans[0][1];
}

// 0 1 1 2 3 5 
// | 0 1 | * |0| = |1|
// | 1 1 |   |1|   |1|

// | 0 1 | * |1| = |1|   ==>  (| 0 1 |) (n) * |0|
// | 1 1 |   |1|   |2|        (| 1 1 |)       |1|   

// | 0 1 | * |1| = |2|
// | 1 1 |   |2|   |3|
// ...


int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t=1;
	cin>>t;
	while(t--){
		cout<<solve()<<'\n';
	}
	return 0;
}
