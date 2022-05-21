class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // // if(prices.size()==0){
        // //     return 0;
        // // }
        // int dp[100005][2];
        // dp[0][0] = 0;
        // dp[0][1] = -prices[0];
        // for(int i = 1;i<prices.size();i++){
        //     dp[i][0] = max(dp[i-1][0],dp[i-1][1]+prices[i]);
        //     dp[i][1] = max(dp[i-1][1],-prices[i]);
        //     // cout<<dp[i][0]<<' '<<dp[i][1]<<endl;
        // }
        // return dp[prices.size()-1][0];
        int res = 0;
        int mid = -prices[0];
        for(int i = 1; i<prices.size(); i++){
            res = max(res, mid+prices[i]);
            mid = max(mid, -prices[i]);
        }
        return res;
    }
};
