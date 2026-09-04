class Solution {
public:

    vector<int> findAnagrams(string s, string p) {
        vector<int> freqs(26,0);
        vector<int> freqp(26,0);
        if(s.size()<p.size()) return {};
        vector<int> ans;
        for(auto& i : p) freqp[i-'a']++;
        for(int j = 0; j<p.size(); j++) freqs[s[j]-'a']++;
        int i = 0, j = p.size();
        while(j<s.size()){
            if(freqp == freqs) ans.push_back(i);
            freqs[s[i++]-'a']--;
            freqs[s[j++]-'a']++;
        }
        if(freqp==freqs) ans.push_back(i);
        return ans;
    }
};