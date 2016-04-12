class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        if len(s) != len(t):
            return False
        letters = [0]*26
        ord_a = ord('a')
        for c in s:
            letters[ord(c) - ord_a] += 1
        for c in t:
            index = ord(c) - ord_a
            letters[index] -= 1
            if letters[index] < 0:
                return False
        return True;