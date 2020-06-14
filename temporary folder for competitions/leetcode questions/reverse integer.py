class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        stringified=str(x)
        new_str=stringified[::-1]
        ans=0
        if(new_str[-1]=='-'):
            new_str=new_str[:-1]
            ans= -1*int(new_str)
        else:
            ans= int(new_str)
        if ans<-2**31 or ans>(2**31)-1 :
            return 0
        else:
            return ans
        