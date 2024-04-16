#include <iostream>
#include <vector>
using namespace std;

int deltaOfSea[8][2] = {{-1, -1},{-1, 0},{-1, 1},{0, 1},{1, 1},{1, 0},{1, -1},{0, -1}};
int deltaOfIsland[4][2] = {{-1, 0},{1, 0},{0, -1},{0, 1}};

int ans = 0;

void DFS_Island(vector<vector<char>>& data, int r, int c, int m, int n){
	data[r][c] = 'N'; 
	
	for(int i = 0; i < 4; ++i){
		int newR = r + deltaOfIsland[i][0];
		int newC = c + deltaOfIsland[i][1];
		if(newR >= 0 && newR < m && newC >= 0 && newC < n){
			if(data[newR][newC] == '1')
				DFS_Island(data, newR, newC, m, n);
		}
	}
}

void DFS_Sea(vector<vector<char>>& data, int r, int c, int m, int n){
	data[r][c] = 'N';
	
	for(int i = 0; i < 8; ++i){
		int newR = r + deltaOfSea[i][0];
		int newC = c + deltaOfSea[i][1];
		if(newR >= 0 && newR < m && newC >= 0 && newC < n){
			if(data[newR][newC] == '1'){
				DFS_Island(data, newR, newC, m, n);
				++ans;
			}
			else if(data[newR][newC] == '0'){
				DFS_Sea(data, newR, newC, m, n);
			}
		}
	}
}

int main()
{
	int t;
	cin >> t;
	vector< vector<vector<char>> > datas;
	for(int i = 0; i < t; ++i){
		int m, n;
		cin >> m >> n;
		vector<vector<char>> data(m + 2, vector<char>(n + 2, '0'));  //扩展一圈0
		for(int r = 1; r < m + 1; ++r){
			for(int c = 1; c < n + 1; ++c){
				cin >> data[r][c];
			}
		}
		datas.push_back(data);
	}
	
	for(int i = 0; i < t; ++i){
		vector<vector<char>> data = datas[i];
		int m = data.size();
		int n = data[0].size();
		
		DFS_Sea(data, 0, 0, m, n);
		
		cout << ans << endl;
		ans = 0;
	}
	
	
	return 0;
}
