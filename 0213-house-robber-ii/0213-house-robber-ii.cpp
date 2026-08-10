class Solution {
public:
    int solve(int i,int end,vector<int>& nums,vector<int>& dp){
        if(i>end) return 0;

        if(dp[i]!=-1) return dp[i];

        int take = nums[i] + solve(i+2,end,nums,dp);
        int skip = solve(i+1,end, nums,dp);

        dp[i] = max(take,skip);

        return dp[i];
    }

    int rob(vector<int>& nums) {
        if(nums.size() == 1)
    return nums[0];

        vector<int> dp1(nums.size(),-1);
        vector<int> dp2(nums.size(),-1);

        int first = solve(0,nums.size()-2,nums,dp1);
        int second = solve(1,nums.size()-1,nums,dp2);

        return max(first,second);
    }
};