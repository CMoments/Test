#include <iostream>
#include <vector>
using namespace std;

// 创建飞机结构体变量
struct plane
{
	int t, d, l;
};
bool vis[15];  // true表示飞机降落，false表示飞机未降落
bool flag;  // 标记是否全部安全降落
vector<plane> p(15);
// 深搜
void dfs(int m, int cnt, int last)  // last表示此前所有飞机降落所需的单位时间
{
	if (cnt == m)
	{
		flag = true;
		return;
	}
	for (int i = 0; i < m; i++)
	{
		if (!vis[i] && p[i].t + p[i].d >= last)  // 只有来的时刻+盘旋时间 > last 的飞机才可以安全降落
		{
			vis[i] = true;
			dfs(m, cnt + 1, max(last, p[i].t) + p[i].l);
			vis[i] = false;
		}
	}
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		for (int i = 0; i < N; ++i)
			cin >> p[i].t >> p[i].d >> p[i].l;
		flag = false;
		dfs(N, 0, 0);
		if (flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
