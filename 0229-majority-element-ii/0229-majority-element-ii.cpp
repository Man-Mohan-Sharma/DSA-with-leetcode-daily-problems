class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int freq = nums.size()/3;
        unordered_map<int,int> hash;
        vector<int> ans;
        for(auto& i : nums) hash[i]++;
        for(auto& i : hash){
            if(i.second>freq) ans.push_back(i.first);
        }
        return ans;
    }
};