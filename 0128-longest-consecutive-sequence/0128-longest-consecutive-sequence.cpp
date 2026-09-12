class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> hash;
        for(auto& i : nums) hash[i]++;
        int ans = 0;
        for(auto& [i,freq] : hash){
            if(hash.find(i-1)==hash.end()){
                int count = 0;
                int num = i;
                while(hash.find(num)!=hash.end()){
                    count++;
                    num++;
                }
            ans = max(count,ans);
            }
        }
        return ans;
    }
};