class Solution {
public:
    string reverseParentheses(string s) {
        string ans = "";
        stack<char> st;
        for(auto& i : s){
            st.push(i);
            if(st.top()==')'){
                st.pop();
                string temp = "";
                while(!st.empty() && st.top()!='('){
                    temp+=st.top();
                    st.pop();
                }
                st.pop();
                for(auto& j : temp) st.push(j);
            }
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};