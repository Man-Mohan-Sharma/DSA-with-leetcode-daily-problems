class Solution {
private:
    int search(vector<int>& nums,int target, int flag){
        int low = 0, high = nums.size()-1;
        int ans = -1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[mid]==target){
                ans = mid;
                if(flag) low = mid+1;
                else high = mid-1;
            }
            else if(nums[mid]>target){
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {search(nums,target,0),search(nums,target,1)};
    }
};