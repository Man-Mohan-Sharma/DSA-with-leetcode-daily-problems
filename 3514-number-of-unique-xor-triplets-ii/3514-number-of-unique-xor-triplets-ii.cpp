class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> s1;
        unordered_set<int> s2;
        for(int i = 0; i<nums.size(); i++){
            for(int j = i; j<nums.size(); j++){
                s1.insert(nums[i]^nums[j]);
            }
        }
        for(auto & i : s1){
            for(int j = 0; j<nums.size(); j++){
                s2.insert(i^nums[j]);
            }
        }
        return s2.size();
    }
};