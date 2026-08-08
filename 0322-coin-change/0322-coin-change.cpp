class Solution {
    int func(vector<int>& v,vector<vector<int>>&dp,int idx,int k){
        if(k==0) return 0;
        if(idx<0) return -1; // No coins left but amount still remains
        if(idx==0){ // only one coin type available
            if(k%v[idx]==0) return k/v[idx];
            else return INT_MAX;
        }
        if(dp[idx][k]!=-1)  return dp[idx][k];
        int take=INT_MAX;
        if (k >= v[idx]) {
            int result = func(v, dp, idx, k - v[idx]);
            if (result != INT_MAX) take = 1 + result;
        }     
       int not_take=func(v,dp,idx-1,k);
        return dp[idx][k]=min(take,not_take);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int res=func(coins,dp,n-1,amount);
        if(res>=1e9) return -1;
        return res;
    }
};