#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s,olds;
	cin >> s;
	olds = s;
	
	sort(s.begin(),s.end());
	int cnt = 0;
	do{
		if(s == olds){
			cout << cnt << endl;
			break;
		}
		cnt ++;
	}while(next_permutation(s.begin(),s.end()));
	return 0;
}
