class Solution:
    def evaluate(self, s, knowledge):
        mp = {}

        for i in knowledge:
            mp[i[0]] = i[1]

        ans = ""
        i = 0

        while i < len(s):
            if s[i] != '(':
                ans += s[i]
            else:
                i += 1
                n = ""

                while s[i] != ')':
                    n += s[i]
                    i += 1

                if n in mp:
                    ans += mp[n]
                else:
                    ans += "?"

            i += 1

        return ans

