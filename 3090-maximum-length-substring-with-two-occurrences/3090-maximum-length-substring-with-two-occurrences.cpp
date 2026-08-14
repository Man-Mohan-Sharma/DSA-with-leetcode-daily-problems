class Solution {
public:
    int maximumLengthSubstring(string s) {
        int ans = 0, j = 0;
        unordered_map<char,int> mp;
        for(int i = 0; i<s.size(); i++){
            mp[s[i]]++;
            while(mp[s[i]]>2){
                mp[s[j]]--;
                j++;
            }
            ans = max(ans,i-j+1);
        }
        return ans;
    }
};