class Solution(object):
    def thirdMax(self, nums):
        maxx = -1e14
        maxx2 = -1e14
        maxx3 = -1e14
        for i in nums:
            if i==maxx or i == maxx2 or i ==maxx3 :
                continue
            elif i>maxx:
                maxx3 = maxx2
                maxx2 = maxx
                maxx = i
            elif i>maxx2:
                maxx3 = maxx2
                maxx2 = i
            elif i>maxx3:
                maxx3 = i
        if maxx3==-1e14:
            return maxx
        else:
            return maxx3