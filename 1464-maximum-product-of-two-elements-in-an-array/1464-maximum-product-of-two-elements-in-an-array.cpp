class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = INT_MIN, pre = INT_MIN;
        for(auto &i : nums){
            if(i>=maxi){
                pre = maxi;
                maxi = i;
            }
            else if(i>=pre && i<=maxi) pre = i;
        }
        return (maxi-1)*(pre-1);
    }
};