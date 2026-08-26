class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string result = "";
        int final_i = 0, final_j = 0, ans = INT_MAX,i = 0;
        int count = 0;
        for(int j = 0; j<s.size(); j++){
            if(s[j]=='1') count++;
            while(count>k){
                if(s[i]=='1') count--;
                i++;
            }
            while(count==k && s[i] == '0') i++;
            if(count == k && 
            (ans > j-i+1 || (ans == j-i+1 && s.substr(i, j-i+1) < result))) {
            ans = j-i+1;
            final_i = i;
            final_j = j;
            result = s.substr(i, j-i+1);
            }
        }
        if(ans == INT_MAX) return "";
        return result;
    }
};