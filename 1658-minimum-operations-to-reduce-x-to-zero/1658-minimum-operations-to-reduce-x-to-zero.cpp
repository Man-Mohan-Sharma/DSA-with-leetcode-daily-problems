class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        long long sum = 0;
        for(auto& i : nums) sum+=i;
        sum = sum-x;
        if(sum<0) return -1;
        int len = -1;
        long long temp = 0;
        int i = 0, j = 0;
        while(j<nums.size()){
            temp+=nums[j];
            while(i<=j && temp>sum) temp-=nums[i++];
            if(temp==sum) len = max(len,j-i+1);
            j++;
        }
        return (len==-1)?-1:nums.size()-len;
    }
};