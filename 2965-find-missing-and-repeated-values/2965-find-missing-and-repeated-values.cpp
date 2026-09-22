class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        long long n = grid.size();
        long long totalsum = 0, givensum = 0, sqsum = 0, sqgiven = 0;
        for(auto& i : grid){
            for(auto& j : i){
                givensum+=j;
                sqgiven+=j*j;
            }
        }
        totalsum = n*n*(n*n+1)/2;
        sqsum = n*n*(n*n+1)*(2*n*n+1)/6;
        long long sumdiff = totalsum-givensum;
        long long sqdiff = sqsum-sqgiven;
        sqdiff = sqdiff/sumdiff;
        int b = (sumdiff+sqdiff)/2;
        return {(int)sqdiff-b,b};
    }
};