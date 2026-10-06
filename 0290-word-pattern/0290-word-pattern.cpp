class Solution {
private:
    vector<string> parse(string& s){
        vector<string> ans;
        stringstream ss(s);
        string cur;
        while(getline(ss,cur,' ')){
            ans.push_back(cur);
        }
        return ans;
    }
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> mp;
        unordered_map<string,char> mp1;
        vector<string> res = parse(s);
        if(res.size()!=pattern.size()) return false;
        for(int i = 0; i<res.size(); i++){
            if(mp.count(pattern[i])==0) mp[pattern[i]] = res[i];
            if(mp1.count(res[i])==0) mp1[res[i]] = pattern[i];
            if(mp[pattern[i]]!=res[i] || mp1[res[i]]!=pattern[i]) return false;
        }
        return true;
    }
};