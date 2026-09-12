class Solution {
    int x = -1e9+7;
public:
    void setZeroes(vector<vector<int>>& matrix) {
        for(int i = 0; i<matrix.size(); i++){
            for(int j = 0; j<matrix[0].size(); j++){
                if(matrix[i][j]==0){
                    for(int k = 0; k<matrix.size(); k++){
                        if(matrix[k][j]!=0) matrix[k][j] = x;
                    }
                    for(int k = 0; k<matrix[0].size(); k++){
                        if(matrix[i][k]!=0) matrix[i][k] = x;
                    }
                }
            }
        }
        for(int i = 0; i<matrix.size(); i++){
            for(int j = 0; j<matrix[0].size(); j++){
                if(matrix[i][j]==x) matrix[i][j] = 0;
            }
        }
    }
};