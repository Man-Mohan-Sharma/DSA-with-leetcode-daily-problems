class Solution {
public:
    vector<string> ans;
    void getString(int n, string &current, int index, int ob, int cb){
        if(index == 2*n){
            ans.push_back(current);
            return;
        }
        if(ob<n){
            current[index] = '(';
            getString(n,current,index+1,ob+1,cb);
        }
        if(cb<n && ob-cb>0){
            current[index] = ')';
            getString(n,current,index+1,ob,cb+1);
        }
    }
    vector<string> generateParenthesis(int n) {
        string current(2*n,'0');
        getString(n,current,0,0,0);
        return ans;
    }
};