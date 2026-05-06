//Day2  6/5/2026
//https://leetcode.com/problems/construct-product-matrix/description/
//medium

class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n= grid.size();
        int m = grid[0].size();
        vector<vector<int>>ans(n,vector<int>(m));
        long long startto=1, endto=1;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                ans[i][j]=startto;
                startto=grid[i][j]*startto%12345;

            }
        }
        for(int i=n-1;i>=0;--i){
            for(int j=m-1;j>=0;--j){
                ans[i][j]=ans[i][j]*endto%12345;
                endto=grid[i][j]*endto%12345;

            }
        }
        return ans;
        
    }
};
