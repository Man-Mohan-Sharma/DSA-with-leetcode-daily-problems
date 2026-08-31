class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> hash;
        int freq = 0;
        int ans = INT_MIN, i = 0;
        for(int j = 0; j<s.size(); j++){
            hash[s[j]]++;
            freq = max(freq,hash[s[j]]);
            int rem = (j-i+1)-freq;
            if(rem<=k) ans = max(ans,j-i+1);
            else hash[s[i++]]--;
        }
        return ans;
    }
};