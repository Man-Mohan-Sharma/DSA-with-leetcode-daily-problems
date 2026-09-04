class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        unordered_map<int,int> maxx , minn;
        int maxi = INT_MIN, mini = INT_MAX;
        for(int i = 0; i<nums.size(); i++){
            maxi = max(maxi, nums[i]);
            mini = min(mini, nums[nums.size()-i-1]);
            maxx[i] = maxi;
            minn[nums.size()-1-i] = mini;
        }
        int ind = -1, cur = INT_MAX;
        for(int i = 0; i<nums.size(); i++){
            if(maxx[i]-minn[i]<=k){
                ind = i;
                break;
            }
        }
        return ind;
    }
};