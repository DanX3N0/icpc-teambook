#include<bits/stdc++.h>
using namespace std;
 
void dfs(vector<vector<bool>> &vis, int r, int c, int n, int m) {
 
  int row = r;
  int col = c;
  vis[row][col] = true;
  int dx[] = {0, 1, 0, -1};
  int dy[] = {1, 0, -1, 0};
 
  for(int i=0;i<4;i++) {
    int nRow = row + dx[i];
    int nCol = col + dy[i];
 
    if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && !vis[nRow][nCol]) {
      dfs(vis, nRow, nCol, n, m);
    }
  }
}
 
int main() {
 
  int n, m; cin >> n >> m;
 
  vector<vector<bool>> vis(n, vector<bool>(m, 0));
 
 
  for(int i=0;i<n; i++) {
    for(int j=0; j<m; j++) {
      char c; cin >> c;
      vis[i][j] = (c=='#');
    }
  }  
 
  int ans = 0;
 
  for(int i=0;i<n; i++) {
    for(int j=0; j<m; j++) {
      if(!vis[i][j]) {
        dfs(vis, i, j, n, m);
        ans++;
      }
    }
  }
 
  cout << ans << endl;
 
}