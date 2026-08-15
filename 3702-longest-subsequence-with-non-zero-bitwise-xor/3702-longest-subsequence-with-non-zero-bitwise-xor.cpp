class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int zero_count = 0, ans = 0;
        for(auto & i : nums){
            ans = ans^i;
            if(i==0) zero_count++;
        }
        if(zero_count==n) return 0;
        return (ans==0)?n-1:n;
    }
};