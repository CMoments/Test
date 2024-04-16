#include<bits/stdc++.h>
using namespace std;
const int M=1e6+5;
int cnt[M],prefix[M]; //cnt记录边的乘积为i的三角形个数
int t;
void dfs(int dep,int st,int mul,int sum){   //dep最大是3（枚举三条边的长度）
	//剪枝              //st确保边的三元组是递增的
	if(mul>1e6) return;
	if(dep==4){
		cnt[mul]++;
		return;   //剪枝2
	}
	int maxn=pow(1e6/mul,1.0/(4-dep))+5; //剪枝3，确定边的最大值
	for(int i=st+1;i<(dep==3 ? sum :maxn);i++){    //枚举边,剪枝4两边之和大于第三边
		dfs(dep+1,i,mul*i,sum+i);
	}
}

int main(){
	dfs(1,1,1,0);
	
	for(int i=1;i<=1e6;i++){    //乘积前缀和
		prefix[i]=prefix[i-1]+cnt[i];
	}
	cin>>t;
	for(int i=1;i<=t;i++){
		int l,r;
		cin>>l>>r;
		cout<<prefix[r]-prefix[l-1]<<endl;
	}
	return 0;
}
