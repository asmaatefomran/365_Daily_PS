//Day3   7/5/2026
//https://leetcode.com/problems/four-divisors/description/
//Medium
//n is the size of the array and m is the max number in the array ---->  O(n(sqrt(m)))

//Just number theaory problem (revision on get the divisors  O(sqrt(n))

class Solution {
public:
    vector<int> getDiv(int num){
        vector<int>ans;
        for(int i=1;1LL*i*i<=num;++i){
            if(num%i==0){
                ans.push_back(i);
            
                if(i!=num/i)ans.push_back(num/i);
                
            }
        }
        return ans;
    }
    int sumFourDivisors(vector<int>& nums) {
        int ans=0;
        for(auto i: nums){
            vector<int>divs=getDiv(i);
            if(divs.size()==4){
                for(auto j:divs)ans+=j;
            }
        }

        return ans;
    }

};
