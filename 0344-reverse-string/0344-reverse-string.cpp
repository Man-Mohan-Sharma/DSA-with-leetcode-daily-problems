class Solution {
private:
    void reverse(vector<char>& s, int i, int j){
        while(i<=j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
    }
public:
    void reverseString(vector<char>& s) {
        reverse(s,0,s.size()-1);
        return ;
    }
};