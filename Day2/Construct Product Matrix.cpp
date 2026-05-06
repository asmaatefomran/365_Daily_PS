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




// I'm very interested about this solution, like the way of thinking about it is totally different, using the unused part of the numbers to store our prefix is totally a great idea of soling this problem in place(without using new space)
//https://leetcode.com/problems/construct-product-matrix/solutions/7671331/0ms-true-o1-space-solution-by-jordinario-bmz4/

func constructProductMatrix(grid [][]int) [][]int {
	const MOD = 12345
	const SHIFT = 16
	const MASK = 1<<SHIFT - 1
	pref := 1
	for i, row := range grid {
		for j := range row {
			val := grid[i][j] % MOD
			grid[i][j] = (pref << SHIFT) | val
			pref = (pref * val) % MOD
		}
	}
	suff := 1
	for i := len(grid) - 1; i >= 0; i-- {
		for j := len(grid[i]) - 1; j >= 0; j-- {
			pref, val := grid[i][j]>>SHIFT, grid[i][j]&MASK
			grid[i][j] = (pref * suff) % MOD
			suff = (suff * val) % MOD
		}
	}
	return grid
}
