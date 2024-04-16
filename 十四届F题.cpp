#include<iostream>
#include<algorithm>
using namespace std;
double a[35], b[35];
int n, m, ans = 1e9, f;

bool cmp(const double &p, const double &q){
	return p > q;
}

//第几个瓜，切了几刀，总和多少
void dfs(int u, int cnt, double sum){
	//如果当前总和大了，或者小了，就减枝
	if(sum > m || sum + b[u] < m) return;
	if(sum == m){
		f = 1;
		ans = min(ans, cnt);
		return;
	}
	//这个判断要放在后面，防止最后一个数没算上就返回了
	if(u > n) return;
	dfs(u + 1, cnt, sum + a[u]);
	dfs(u + 1, cnt + 1, sum + a[u] / 2);
	dfs(u + 1, cnt, sum);
}

int main()
{
	cin>>n>>m;
	for(int i = 1; i <= n; i++) cin>>a[i];
	//降序排列，先加重量大的
	sort(a + 1, a + n + 1, cmp);
	//存储后缀和，用来减枝
	for(int i = n; i > 0; i--) b[i] = b[i + 1] + a[i];
	dfs(1, 0, 0);
	if(!f) printf("-1");
	else printf("%d", ans);
	return 0;
}
