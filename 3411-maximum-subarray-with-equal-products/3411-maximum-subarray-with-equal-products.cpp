class Solution {
public:
    int maxLength(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int pro=1;
            int g=0;
            int lc=1;
            for(int j=i;j<nums.size();j++){
                pro*=nums[j];

                g=gcd(g,nums[j]);
                lc=lcm(lc,nums[j]);


                if(pro==g*lc)ans = max(ans,j-i+1);
                if(pro>g*lc)break;
            }
        }
        return ans;
    }
};