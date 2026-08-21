class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>> pq;
        unordered_map<int,int> mp;
        for(auto& it : nums) mp[it]++;
        for(auto& it : mp) pq.push({it.second,it.first});
        vector<int> result;
        for(int i = 1; i<=k; i++){
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};