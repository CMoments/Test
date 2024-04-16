#include <bits/stdc++.h>
using namespace std;
const int N = 105;
stack<char> stk;
char s[N];
int main()
{
	int n; cin >> n;
	cin >> s+1;
	bool ans = true;
		
	for(int i = 1;i<= n;++i){
		if(s[i] == '(')stk.push('(');
		else{
			if(stk.size() && stk.top() == '(')stk.pop();
			else ans = false;
		}
	}
	if(stk.size())ans = false;
	cout << (ans ?"Yes":"No") << '\n';
	return 0;
}
