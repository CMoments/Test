#include <bits/stdc++.h>
using namespace std;
string v[50];
int dir[8][2] = {1,0,-1,0,0,1,0,-1,1,1,-1,-1,1,-1,-1,1};
int vis[50][50];
int m, n;
int ans;
bool bfs(int x, int y){
	queue<pair<int,int>>q;
	q.push({x,y});
	while(!q.empty()){
		int curx = q.front().first, cury = q.front().second;
		q.pop();
		for(int i = 0; i < 8; i++){
			int nx = curx + dir[i][0];
			int ny = cury + dir[i][1];
			if(nx < 0 || ny < 0 || nx >= m || ny >= n){
				return false;
			}
			if(v[nx][ny] == '0' && vis[nx][ny] == 0) {
				vis[nx][ny] = 1;
				q.push({nx, ny});
			}
		}
	}
	return true;
}
void dfs(int x, int y){
	if(x >= m || y >= n || x < 0 || y < 0) return;
	if(v[x][y] == '1') v[x][y] = '2';
	else return;
	for(int i = 0; i < 4; i++){
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];
		dfs(nx, ny);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		ans = 0;
		cin>>m>>n;
		for(int i = 0; i < m; i++){
			cin>>v[i];
		}
		for(int i = 0 ; i < m; i++){
			for(int j = 0; j < n; j++){
				if(v[i][j] == '1') {
					dfs(i,j);
					memset(vis, 0, sizeof(vis));
					if(bfs(i,j)) ans--;
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
