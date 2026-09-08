class Solution {
    int dr[4] = {1,0,-1,0}, dc[4] = {0,1,0,-1};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,pair<int,int>>>  qu; // {time,{i,j}}
        int fresh = 0;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,-1));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j]==2){
                    qu.push({0,{i,j}});
                    visited[i][j] = 1;
                    }
                if(grid[i][j]==1) fresh++;
            }
        }
        int time = 0;
        int rotted = 0;
        while(!qu.empty()){
            time = qu.front().first;
            auto [i,j] = qu.front().second;
            qu.pop();
            for(int k = 0; k<4; k++){
                int r = i+dr[k], c = j+dc[k];
                if((r>=0&&r<n) && (c>=0&& c<m) && grid[r][c]==1 && visited[r][c] == -1){
                    visited[r][c] = 1;
                    grid[r][c] = 2;
                    qu.push({time+1,{r,c}});
                    rotted++;
                }
            }
        }
        return (fresh==rotted)?time:-1;
    }
};