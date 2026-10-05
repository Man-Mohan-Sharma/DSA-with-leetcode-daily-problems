class Solution(object):
    def scoreOfParentheses(self, s):
        score = 0
        res = []
        for i in range(0,len(s)):
            if s[i]=='(':
                res.append(score)
                score = 0
            else:
                if s[i-1]=='(':
                    score = 1+res[-1]
                else:
                    score = 2*score + res[-1]
                res.pop()

        return score
        