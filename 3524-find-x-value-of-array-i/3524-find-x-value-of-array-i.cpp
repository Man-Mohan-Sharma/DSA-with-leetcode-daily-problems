class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
       vector<long long> result(k,0);
       vector<long long> pre(k,0);
       for(int i = 0; i<nums.size(); i++){
        vector<long long> count(k,0);
        count[nums[i]%k]++;
        for(int oldrem = 0; oldrem<k; oldrem++){
            int newrem = (oldrem*(nums[i]%k))%k;
            count[newrem]+=pre[oldrem];
        }
        pre = count;
        for(int j = 0; j<k; j++) result[j]+=count[j];
       }
       return result;
    }
};