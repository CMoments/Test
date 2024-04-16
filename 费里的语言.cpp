#include<iostream>
#include<map>
using namespace std;
map<string,bool>mp;

int main()
{
	int n;
	string ans = "NO";
	cin >> n;
	
	for(int i = 0;i < n;++ i)
	{
		string word;
		cin >> word;
		if(mp.count(word)){
			ans = word;
			break;
		}
		
		else  mp[word] = 1;
	}
	cout << ans << endl;
	
	return 0;
}

