#include<bits/stdc++.h>
using namespace std;

int main(){
	
	int n;cin >> n;
	
	
	vector<int>a(n);
	
	for(int i = 0;i < n;++ i)
	{
		cin >> a[i];
	}
	
	vector<int> S;
	for(int i = 0;i < n;++ i){
		if(S.empty() || a[i] > S.back()){
			S.push_back(a[i]);
		}else{
			auto it = lower_bound(S.begin(),S.end(),a[i]);
			*it = a[i];
		}
	}
	cout << S.size() << endl;
	
	return 0;
}
