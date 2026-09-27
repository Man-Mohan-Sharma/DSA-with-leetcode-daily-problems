class Solution:
    def reverseParentheses(self, s):
        ans = ""
        st = []
        
        for i in s:
            st.append(i)

            if st[-1] == ')':
                st.pop()
                temp = ""

                while st and st[-1] != '(':
                    temp += st[-1]
                    st.pop()

                st.pop()

                for j in temp:
                    st.append(j)

        while st:
            ans += st[-1]
            st.pop()

        ans = ans[::-1]
        return ans