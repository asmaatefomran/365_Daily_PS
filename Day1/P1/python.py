class Solution:
    def minimumCost(self, cost: List[int]) -> int:
        paid = 0
        cost.sort(reverse=True)
        for i in range(len(cost)):
            if i % 3 !=2:
                paid+=cost[i]
    
        return paid
        
