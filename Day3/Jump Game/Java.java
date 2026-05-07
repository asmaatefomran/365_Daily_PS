class Solution {
    public int[] maxValue(int[] nums) {
        int n = nums.length;
        int[] prefmx= new int[n];
        prefmx[0]=nums[0];
        for(int i=1;i<n;++i){
            prefmx[i]=Math.max(prefmx[i-1],nums[i]);
        }
        int[] ans = new int[n];
        ans[n-1]=prefmx[n-1];
        int suffmn=nums[n-1];
        for(int i=n-2;i>=0;--i){
            if(prefmx[i]>suffmn){
                ans[i]=ans[i+1];
            }else{
                ans[i]=prefmx[i];
            }
            suffmn= Math.min(suffmn,nums[i]);
        }
        return ans;
        
    }
}
