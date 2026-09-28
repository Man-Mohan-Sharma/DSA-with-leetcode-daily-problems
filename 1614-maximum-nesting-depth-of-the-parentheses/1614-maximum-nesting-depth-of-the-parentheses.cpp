class Solution {
public:
    int maxDepth(string s) {
        int count = 0, ans = INT_MIN;
        for(auto & i : s){
            if(i=='(') count++;
            else if(i==')') count--;
            ans = max(ans,count);
        }
        return ans;
    }
};