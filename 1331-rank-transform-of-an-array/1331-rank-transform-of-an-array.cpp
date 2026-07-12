class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> brr = arr;
        sort(brr.begin(),brr.end());
        unordered_map<int,int> mp;
        int count = 0;
        for(int i = 0; i<brr.size(); i++){
            if(mp.contains(brr[i])) continue;
            else mp[brr[i]] = count++;
        }
        for(auto & i : arr){
            i = mp[i]+1;
        }
        return arr;
    }
};