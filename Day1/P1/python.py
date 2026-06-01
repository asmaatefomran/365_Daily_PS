#2144. Minimum Cost of Buying Candies With Discount
#1/6/2026
#easy
#https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/
class Solution:
    def minimumCost(self, cost: List[int]) -> int:
        paid = 0
        cost.sort(reverse=True)
        for i in range(len(cost)):
            if i % 3 !=2:
                paid+=cost[i]
    
        return paid
        
