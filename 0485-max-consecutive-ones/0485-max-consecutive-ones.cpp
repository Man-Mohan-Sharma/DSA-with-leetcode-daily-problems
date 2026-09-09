class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0, i = 0, j = 0;
        while(i<nums.size() && j < nums.size()){
            if(nums[j]==1){
                ans = max(ans,j-i+1);
                j++;
            }
            else{
                j++;
                i = j;
            }
        }
        return ans;
    }
};