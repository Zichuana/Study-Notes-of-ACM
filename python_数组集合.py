class Solution(object):
    def combine(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[List[int]]
        """
        nums = [i+1 for i in range(n)]
        return [j for j in combinations(nums, k)]
