#include<iostream>
using namespace std;
int ans = 0;
void dfs(int k,int r){
	if( r == 70)ans ++;
	if( k == 30 || r == 100)return ;
	dfs(k + 1,r + 10);
	dfs(k + 1,0);
}
int main()
{
	dfs(0,0);
	cout << ans << endl;
	
	return 0;
}
