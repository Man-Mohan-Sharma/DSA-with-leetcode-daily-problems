class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxx = INT_MIN, sum = 0;
        for(auto & i : nums){
            if(sum<0) sum = 0;
            sum+=i;
            maxx = max(maxx,sum);
        }
        return maxx;
    }
};