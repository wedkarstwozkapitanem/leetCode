
# =========================== #
#  Dominik Łempicki (kapitan) #
# =========================== #

class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        tab = s.strip().split(" ")
        return len(tab[len(tab)-1])