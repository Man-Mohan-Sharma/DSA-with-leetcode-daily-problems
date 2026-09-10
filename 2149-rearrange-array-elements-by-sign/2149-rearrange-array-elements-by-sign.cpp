class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> positive;
        vector<int> negative;
        for(auto& i : nums) (i<0)?negative.push_back(i):positive.push_back(i);
        int i = 0, j = 0;
        for(int k = 0; k<nums.size(); k++){
            if(k&1) nums[k] = negative[j++];
            else nums[k] = positive[i++];
        }
        return nums;
    }
};