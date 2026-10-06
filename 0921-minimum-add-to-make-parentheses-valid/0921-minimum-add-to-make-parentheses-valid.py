class Solution(object):
    def minAddToMakeValid(self, s):
        count = 0
        open = 0
        for i in s:
            if i=='(':
                count = count+1
                open = open+1
            else:
                if open>0:
                    count = count-1
                    open = open-1
                else:
                    count = count+1

        return count
        