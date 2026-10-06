class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0, count = 0;
        for(auto& i : s){
            if(i=='('){
                count++;
                open++;
            }
            else{
                if(open>0){
                    count--;
                    open--;
                }
                else count++;
            }
        }
        return count;
    }
};