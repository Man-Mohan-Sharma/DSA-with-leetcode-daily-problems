class Solution {
private:
    void reverse(vector<int>& nums, int i, int j){
        while(i<=j){
            swap(nums[i],nums[j]);
            i++;
            j--;
        }
    }
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size()-1;
        k = k%(n+1);
        reverse(nums,0,n-k);
        reverse(nums,n-k+1,n);
        reverse(nums,0,n);
        return;
    }
};