class Solution {
private: 
    void reverse(vector<int>& temp, int i, int j){
        while(i<=j){
            swap(temp[i],temp[j]);
            i++;
            j--;
        }
    }
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<int> temp;
        for(auto &i : grid){
            for(auto &j : i) temp.push_back(j);
        }
        int n = temp.size();
        k = k%n;
        reverse(temp,0,n-k-1);
        reverse(temp,n-k,n-1);
        reverse(temp,0,temp.size()-1);
        k = 0;
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                grid[i][j] = temp[k++];
            }
        }
        return grid;
    }
};