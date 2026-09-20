class Solution(object):
    def reverseDegree(self, s):
        j = 1
        ans = 0
        for i in s:
            temp = ord(i)-97
            ans = ans+(26-temp)*j
            j = j+1
        return ans