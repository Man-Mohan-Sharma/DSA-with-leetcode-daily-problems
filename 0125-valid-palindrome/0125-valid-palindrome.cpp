class Solution {
private:
    bool is_palindrome(string& s){
        int i = 0, j = s.size()-1;
        while(i<=j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
public:
    bool isPalindrome(string s) {
       string ans = "";
       for(auto& i : s){
        if(i>='a'&&i<='z' || i>='0'&&i<='9') ans+=i;
        else if(i>='A'&&i<='Z') ans+='a'+(i-'A');
       }
       return is_palindrome(ans);
    }
};