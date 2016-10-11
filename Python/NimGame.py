class Solution(object):
    def canWinNim(self, n):
        """
        :type n: int
        :rtype: bool
        """
        return self.whoWin(n, True)
    #version 1: exceed maximum recursion depth
    def whoWin(self, n, isYou):
        if n <= 3:
            return isYou
        for i in [1,2,3]:
            win = self.whoWin(n - i, not isYou)
            if True == win:
                break
        return win

if __name__ == '__main__':
    nimGame = Solution()
    print nimGame.canWinNim(4)