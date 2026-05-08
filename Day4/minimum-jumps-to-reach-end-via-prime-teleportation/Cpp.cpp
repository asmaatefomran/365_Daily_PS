//Day4 8/5/2026
//https://leetcode.com/problems/minimum-jumps-to-reach-end-via-prime-teleportation/description/
//medium

// i first tried to soled dp , but doesn't work because the relation between indexs can be cyclic
//new reminder to me: dp can be used only we can say "there is no way that after calculating the cost for a place that this place can have a better cost if we returned to it again  (this cycle not in dp )

#include <bits/stdc++.h>
using namespace std;

 static vector<int> spf;
 static bool built;

    void sieve(int MAXV) {
        spf.resize(MAXV + 1);

        for (int i = 0; i <= MAXV; ++i)
            spf[i] = i;

        for (int i = 2; i * i <= MAXV; ++i) {
            if (spf[i] == i) {
                for (int j = i * i; j <= MAXV; j += i) {
                    if (spf[j] == j)
                        spf[j] = i;
                }
            }
        }
        built = true;
    }

    bool isPrime(int x) {
        return x >= 2 && spf[x] == x;
    }

vector<int> primeFactorization(int n) {
    vector<int> primes;

    for (int i = 2; 1LL * i * i <= n; ++i) {

        if (n % i == 0) {
            primes.push_back(i);
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    if (n > 1) {
        primes.push_back(n);
    }

    return primes;
}
   
    int minJumps(vector<int>& nums) {
        int n= nums.size();
        int MAXV = 1e6;

        if(!built)sieve(MAXV);
        map<int,vector<int>>ptoi;
        for(int i=0;i<n;++i){
            vector<int> f= primeFactorization(nums[i]);
            for(auto j:f){
                ptoi[j].push_back(i);
            }
        }

        vector<int>dist(n,-1);
        queue<int>q;
        unordered_set<int>donep;
        dist[0]=0;
        q.push(0);
        while(!q.empty()){
            int i = q.front();
            q.pop();
            if(i == n-1)return dist[i];

            if(i-1>0&&dist[i-1]==-1){
                dist[i-1]=dist[i]+1;
                q.push(i-1);
            }
            if(i+1<n&&dist[i+1]==-1){
                dist[i+1]=dist[i]+1;
                q.push(i+1);
            }
            if(isPrime(nums[i])){
                if(!donep.count(nums[i])){
                    donep.insert(nums[i]);
                    for(auto j: ptoi[nums[i]]){
                        if(dist[j]==-1){
                            dist[j]=dist[i]+1;
                            q.push(j);
                        }
                    }
                }
            }
        }
        return 0;
        
    }
int main (){
    
}
