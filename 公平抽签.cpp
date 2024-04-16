#include <iostream>
#include <vector>
using namespace std;

int n; //共计N个数
int m; //选m个数
vector<string> name;
vector<string> ans;
vector<int> chosen;
void calc(int x)
{
	
	if (chosen.size() > m || chosen.size() + (n - x + 1) < m) //剪枝
		return;
	
	if (x == n + 1)
	{ //选够了m个数输出
		string ansTem = "";
		for (int i = 0; i < chosen.size(); i++)
			ansTem += name[chosen[i] - 1] + " ";
		
		ans.push_back(ansTem);
		return;
	}
	chosen.push_back(x);
	calc(x + 1);
	
	chosen.pop_back(); //消除痕迹
	calc(x + 1);
	
}
int main()
{
	
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		name.push_back(s);
	}
	calc(1);
	for (int i =0; i < ans.size(); i++)
		cout << ans[i] << endl;
}
