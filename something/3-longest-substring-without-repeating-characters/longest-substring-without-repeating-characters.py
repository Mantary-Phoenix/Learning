class Solution(object):
    def lengthOfLongestSubstring(self, s):
        i = 0
        prev_count = 0
        count = 0
        for i in range(len(s)):
            count = 0
            list1 = []
            for ch in s[i:]:
                if ch not in list1:
                    list1.append(ch)
                    count = count + 1
                else:
                    break
            if count > prev_count:
                prev_count = count
        return prev_count