class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int> st;
        vector<int> ans(temp.size());
        for(int i = temp.size()-1; i>=0; i--){
            if(st.empty()){
                ans[i] = 0;
                st.push(i);
            }
            else{
                if(temp[i]>=temp[st.top()]){
                    while(!st.empty()){
                        st.pop();
                        if(st.empty() || temp[st.top()]>temp[i]) break;
                    }
                    if(st.empty()) ans[i] = 0;
                    else ans[i] = st.top() - i;
                    st.push(i);
                }
                else{
                    ans[i] = 1;
                    st.push(i);
                }
            }
        }
        return ans;
    }
};