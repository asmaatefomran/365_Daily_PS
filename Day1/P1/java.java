//2144. Minimum Cost of Buying Candies With Discount
//1/5/2026
//easy
//https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/

import java.util.*;
class Solution {
    public int minimumCost(int[] cost) {
        Arrays.sort(cost);
        int size = cost.length;
        int paid=0,curr=0;
        for(int i=size-1;i>=0;i--){
            if(curr<2){
                curr++;
                paid+=cost[i];
            }
            else{
                curr=0;
            }
        }
        return paid;
        
    }
}
