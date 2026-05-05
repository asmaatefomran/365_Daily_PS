//Day1    5/5/2026
//https://leetcode.com/problems/minimum-distance-to-type-a-word-using-two-fingers/description/
//hard 


class Solution {
public:
    int minimumDistance(string word) {
        unordered_map<char,pair<int,int>>keyboard;
        char curr ='A';
        for(int i=0;i<5;++i){
            for(int j=0;j<6;++j){
                if(i==4&& j>1)break;
                keyboard[curr]=make_pair(i,j);
                curr++;
            }
        }
        int dp[27][27][301];
        int n = word.size();

        for(int i = 0; i < 27; ++i)
            for(int j = 0; j < 27; ++j)
                for(int k = 0; k <= n; ++k)
                    dp[i][j][k] = INT_MAX;

        dp[26][26][0] = 0;//both fingers are unused
        auto dist=[&](int c,int p){
            if(p==26)return 0;
            int x=abs(keyboard['A'+c].first-keyboard['A'+p].first);
            int y=abs(keyboard['A'+c].second-keyboard['A'+p].second);
            return x+y;

        };

        for(int k=1;k<=n;++k){
            int indx= word[k-1]-'A';

            for(int l=0;l<27;++l){
                for(int r=0;r<27;++r){
                    if(dp[l][r][k-1]==INT_MAX)continue;

                    //left
                    dp[indx][r][k]=min(dp[l][r][k-1] + dist(indx,l),dp[indx][r][k]);

                    //right
                    dp[l][indx][k]= min(dp[l][r][k-1]+dist(indx,r),dp[l][indx][k]);
                }

            }
            
        }
         int ans = INT_MAX;
            for(int i=0;i<27;++i){
                for(int j=0;j<27;++j){
                    ans= min(ans,dp[i][j][n]);
                }
            }

        return ans;
    }

};
