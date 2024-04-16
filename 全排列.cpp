#include<bits/stdc++.h>
using namespace std;
int n;
int m;
bool chosen[20];
int order[20];
void calc(int k)
{
	if(k == n + 1)
	{
		for(int i = 1;i <= n;++ i)
			cout << order[i] << " ";
	puts("");
	return;
	}
	for(int i = 1;i <= n;++ i)
	{
		if(chosen[i])
			continue;
		order[k] = i;
		chosen[i] = 1;
		calc(k + 1);
		chosen[i] = 0;
		order[k] = 0;
	}
}

int main()
{
	cin >> n;
	calc(1);
	return 0;
}
/*
  
  #include<bits/stdc++.h>
  using namespace std;
  int n;//共计N个数
  int m;//选m个数
  vector<int> chosen;
  string s[1000];
  void calc(int x) {
  if (chosen.size() > m || chosen.size() + (n - x + 1) < m) //剪枝
  return;
  if (x == n + 1) { //选够了m个数输出
  for (int i = 0; i < chosen.size(); i++)
  cout<< s[chosen[i]]<<" ";//也可以不输出，存放起来也是可以的，主要是看题目。
  puts("");
  return;
  }
  chosen.push_back(x);
  calc(x + 1);
  chosen.pop_back();//消除痕迹
  calc(x + 1);
  }
  int main()
  {
  cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
  cin>>s[i];
  }
  calc(1);
  }
  */
