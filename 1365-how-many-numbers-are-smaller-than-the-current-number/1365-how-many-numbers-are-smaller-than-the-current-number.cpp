class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> ans(nums.size());
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for(int i = 0; i < nums.size(); i++){
            pq.push({nums[i], i});
        }

        int count = 0, pre = -1, freq = 0;

        while(!pq.empty()){
            auto [node, idx] = pq.top();

            if(pre != node){
                count += freq;
                pre = node;
                freq = 1;
            }
            else{
                freq++;
            }

            ans[idx] = count;

            pq.pop();
        }

        return ans;
    }
};