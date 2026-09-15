class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> st;
        for(int i = 0; i<nums.size(); i++){
            for(int j = i+1; j<nums.size(); j++){
                unordered_map<long long,int> hash;
                long long sum = 1LL*target-nums[i]-nums[j];
                for(int k = j+1; k<nums.size(); k++){
                    long long rem = (sum-nums[k]);
                    if(hash.find(rem)!=hash.end()){
                        vector<int> temp = {nums[i],nums[j],nums[k],nums[hash[rem]]};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                    hash[nums[k]] = k;
                }
            }
        }
        return vector<vector<int>>(st.begin(),st.end());
    }
};