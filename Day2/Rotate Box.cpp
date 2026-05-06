//Day 2    6/5/2026
//https://leetcode.com/problems/rotating-the-box/description/
//Medium
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n= boxGrid.size();
        int m=boxGrid[0].size();
        vector<vector<int>>suffix(n);
        int count=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(boxGrid[i][j]=='*'){
                    suffix[i].push_back(count);
                    count=0;
                }
                if(boxGrid[i][j]=='#')count++;
            }
            suffix[i].push_back(count);
            count=0;
        }
        vector<vector<char>>ans(n,vector<char>(m,'.'));
        for(int i=0;i<n;++i){
            int j=m-1;
            int count=0;
            while(j>=0){
                count = suffix[i].back();
                suffix[i].pop_back();
                while(count--){
                    ans[i][j]='#';
                    j--;
                }
                while(j>=0&&boxGrid[i][j]!='*'){
                    ans[i][j]='.';
                    j--;
                }
                if(j>=0){
                    ans[i][j]='*';
                }
                j--;
            }
        }
         vector<vector<char>>res(m,vector<char>(n,'.'));
         for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                res[j][i]=ans[n-i-1][j];
            }
         }
         return res;
        
    }


//optimal solution using one addition 2d vector only instead of two 
vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();

        vector<vector<char>> ans(n, vector<char>(m, '.'));

        for(int i = 0;i<m;i++){
            int x = n - 1;
            for(int j = n-1;j>=0;j--){
                //when ever you fix jem put it at the pointer x
                if(boxGrid[i][j]=='#'){
                    ans[x][m-i-1] = '#';
                    x--;
                }
                    //when ever you find wall jump the pointer x to it and put it and start from this point in the next step
                else if(boxGrid[i][j]=='*'){
                    ans[j][m-i-1] = '*';
                    x = j - 1;
                }
            }
        }

        return ans;
    }
};



