class Solution {
    int dr[4] = {1,0,-1,0}, dc[4] = {0,1,0,-1};
private:
    void bfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>> & visited){
        queue<pair<int,int>> qu;
        qu.push({i,j});
        visited[i][j] = true;
        while(!qu.empty()){
            auto [i,j] = qu.front();
            qu.pop();
            for(int k = 0; k<4; k++){
                int ni = i+dr[k], nj = j+dc[k];
                if(ni>=0&& ni<grid.size() && nj>=0&&nj<grid[0].size() && !visited[ni][nj] && grid[ni][nj] == '1'){
                    qu.push({ni,nj});
                    visited[ni][nj] = true;
                    }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        int ans = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    ans++;
                    bfs(i,j,grid,visited);
                }
            }
        }
        return ans;
    }
};