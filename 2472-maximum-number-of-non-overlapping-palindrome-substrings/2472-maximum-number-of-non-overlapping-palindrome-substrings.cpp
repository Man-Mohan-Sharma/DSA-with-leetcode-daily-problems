class Solution {
private:
    bool is_plindrome(string& s, int i, int j){
        while(i<=j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int solve(string& s, int k , int i, int j,vector<vector<int>>& dp){
        if(i>=s.size() || j>=s.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(is_plindrome(s,i,j)){
            int take = 1+solve(s,k,j+1,j+k,dp);
            int grow = solve(s,k,i,j+1,dp);
            int slide = solve(s,k,i+1,j+1,dp);
            return dp[i][j] = max(take,max(grow,slide));
        }
        else{
            int grow = solve(s,k,i,j+1,dp);
            int slide = solve(s,k,i+1,j+1,dp);
            return dp[i][j] = max(grow,slide);
        }
    }

public:
    int maxPalindromes(string s, int k) {
        if(k==1) return s.size();
        vector<vector<int>> dp(s.size()+1,vector<int>(s.size()+1,-1));
        return solve(s,k,0,k-1,dp);
    }
};