class Solution(object):
    def wordPattern(self, pattern, s):
       mp1 = {}
       mp2 = {}
       res = s.split(' ')
       if len(pattern)!=len(res):
            return False
       for i in range(0,len(pattern)):
            if pattern[i] not in mp1:
                mp1[pattern[i]] = res[i]
            if res[i] not in mp2:
                mp2[res[i]] = pattern[i]
            if mp1[pattern[i]]!=res[i] or mp2[res[i]]!=pattern[i]:
                return False
       return True
        