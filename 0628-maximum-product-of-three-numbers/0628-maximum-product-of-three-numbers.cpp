class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int pre1 = INT_MIN, pre = INT_MIN, maxi = INT_MIN;
        int premin = INT_MAX, mini = INT_MAX;
        for(auto & i : nums){
            if(i>=maxi){
                pre1 = pre;
                pre = maxi;
                maxi = i;
            }
            else if(i>=pre && i<=maxi){
                pre1 = pre;
                pre = i;
            }
            else if(i>=pre1 && i<=pre){
                pre1 = i;
            }
            if(i<=mini){
                premin = mini;
                mini = i;
            }
            else if(i<=premin && i>=mini){
                premin = i;
            }
        }
        return max(premin*mini*maxi,pre1*pre*maxi);
    }
};