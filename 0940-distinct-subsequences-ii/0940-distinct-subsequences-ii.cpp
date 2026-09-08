class Solution {
    int MOD = 1e9+7;
    int solve(string& s, int i, vector<int>& dp, vector<int>& pre){
        if(i==0) return 1;
        int total = (solve(s,i-1,dp,pre)*2)%MOD;
        int repeat = 0;
        if(pre[i]!=0) repeat = dp[pre[i]-1];
        return dp[i] = (total-repeat+MOD)%MOD;
    }
public:
    int distinctSubseqII(string s) {
        int n = s.size();
        vector<int> dp(n+1,1);
        vector<int> pre(n+1,0), lastseen(26,0);
        for(int i = 1; i<=n; i++){
            int ind = s[i-1]-'a';
            pre[i] = lastseen[ind];
            lastseen[ind] = i;
        }
        return (solve(s,n,dp,pre)-1+MOD)%MOD;
        
    }
};