class Solution {
private:
    int solve(string& s, int k , int i, int j,vector<vector<int>>& dp,vector<vector<bool>>& is_palindrome){
        if(i>=s.size() || j>=s.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(is_palindrome[i][j]){
            int take = 1+solve(s,k,j+1,j+k,dp,is_palindrome);
            int grow = solve(s,k,i,j+1,dp,is_palindrome);
            int slide = solve(s,k,i+1,j+1,dp,is_palindrome);
            return dp[i][j] = max(take,max(grow,slide));
        }
        else{
            int grow = solve(s,k,i,j+1,dp,is_palindrome);
            int slide = solve(s,k,i+1,j+1,dp,is_palindrome);
            return dp[i][j] = max(grow,slide);
        }
    }

public:
    int maxPalindromes(string s, int k) {
        if(k==1) return s.size();
        vector<vector<bool>> is_palindrome(s.size()+1,vector<bool>(s.size()+1,false));
        for(int l = 1; l<=s.size(); l++){
            for(int i = 0; i+l<=s.size(); i++){
                int j = i+l-1;
                if(i==j) is_palindrome[i][j] = true;
                else if(i+1 == j) is_palindrome[i][j] = (s[i]==s[j])?true:false;
                else is_palindrome[i][j] = (s[i]==s[j] && is_palindrome[i+1][j-1])?true:false;
            }
        }
        vector<vector<int>> dp(s.size()+1,vector<int>(s.size()+1,-1));
        return solve(s,k,0,k-1,dp,is_palindrome);
    }
};