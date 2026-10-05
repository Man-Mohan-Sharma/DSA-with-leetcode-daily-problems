class Solution {
public:
    int scoreOfParentheses(string s) {
        vector<int> res;
        int score = 0;
        for(int i = 0; i<s.size(); i++){
            if(s[i]=='('){
                res.push_back(score);
                score = 0;
            }else{
                if(s[i-1]=='(') score = 1+res.back();
                else score = score*2+res.back();
                res.pop_back();
            }
        }
        return score;
    }
};