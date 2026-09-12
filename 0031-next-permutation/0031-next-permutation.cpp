class Solution {
private:
    void reverse(vector<int>& nums, int i, int j){
        while(i<=j){
            swap(nums[i],nums[j]);
            i++;
            j--;
        }
        return;
    }
public:
    void nextPermutation(vector<int>& nums) {
        int idx = -1;
        int n = nums.size();
        for(int i = n-2; i>=0; i--){
            if(nums[i]<nums[i+1]){
                idx = i;
                break;
            }
        }
        if(idx == -1){
            reverse(nums,0,n-1);
            return;
        }
        else{
            for(int i = n-1; i>=0; i--){
                if(nums[i]>nums[idx]){
                    swap(nums[i],nums[idx]);
                    break;
                }
            }
            reverse(nums,idx+1,n-1);
        }
        return;
    }
};