class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26,0);
        for(auto & i : s) freq[i-'a']++;

        string ans = "";
        int ind = 0;
        char ch;
        for(int i = 0; i<26; i++){
            if(freq[i]%2==1){
                freq[i]--;
                ind = 1;
                ch = char(i+'a');
            }
            while(freq[i]>0){
                ans+=char(i+'a');
                freq[i]-=2;
            }
        }
        string k = ans;
        reverse(k.begin(),k.end());
        if(ind == 1) ans = ans+ch+k;
        else ans = ans+k;
        return ans;
    }
};