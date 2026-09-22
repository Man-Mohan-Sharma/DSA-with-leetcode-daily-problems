class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> frq(n*n+1,0);
        for(auto& i : grid) 
            for(auto& j: i) frq[j]+=1;
        int a, b;
        for(int i = 1; i<=n*n; i++){
            if(frq[i]==0) b = i;
            if(frq[i]==2) a = i;
        }
        return {a,b};
    }
};