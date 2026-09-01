class Solution {
public:
    int rob(vector<int>& nums) {
        int first = 0, second = nums[0], thrid = 0;
        for(int i = 1; i<nums.size(); i++){
            thrid = max(nums[i]+first,second);
            first = second;
            second = thrid;
        }
        return second;
    }
};