//Day3   7/5/2026
//leetcode.com/problems/jump-game-ix/description/
//Medium

//the problem seamed like segment tree or something related to the mx and mn ranges but it's easier that it, it depends on the inversion concetivity

class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefmx(n),ans(n);
        prefmx[0]=nums[0];
        for(int i=1;i<n;++i){
           prefmx[i]=max(prefmx[i-1],nums[i]);
        }
        int suffmn= nums[n-1];
        ans[n-1]=prefmx[n-1];
        for(int i=n-2;i>=0;--i){
            if(prefmx[i]>suffmn){
                ans[i]=ans[i+1];  //same connected component as the previous one
            }
            else{
                ans[i]=prefmx[i]; //new connected component
            }
            suffmn=min(suffmn,nums[i]);
        }

        return ans;
    }
};
