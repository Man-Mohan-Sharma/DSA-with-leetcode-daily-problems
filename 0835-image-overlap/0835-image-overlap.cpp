class Solution {
private:
    int overlap(const vector<vector<int>>& img1, const vector<vector<int>>& img2, int dr, int dc){
        int count = 0;
        for(int i = 0; i<img1.size(); i++){
            for(int j = 0; j<img1[0].size(); j++){
                int ni = i+dr, nj = j+dc;
                if((ni>=0&& ni<img2.size())  && (nj>=0 && nj<img2[0].size())){
                    if(img1[i][j] == 1 && img2[ni][nj]==1) count++;
                }
            }
        }
        return count;
    }
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int count = 0;
        int n = img1.size();
        for(int i = 1-n; i<=n-1; i++){
            for(int j = 1-n; j<=n-1; j++){
                count = max(count,overlap(img1,img2,i,j));
            }
        }
        return count;
    }
};