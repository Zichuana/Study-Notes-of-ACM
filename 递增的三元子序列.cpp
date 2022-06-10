class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int len = nums.size();
        if(len < 3) return false;
        // int flag = 1;
        // for(int i = 0;i<len-1;i++){
        //     if(nums[i]<nums[i+1]){
        //         flag = 0;
        //         break;
        //     }
        // }
        // if(flag){
        //     return false;
        // }
        // for(int i = 1; i < len-1 ; i++){
        //     int mi = nums[0], ma = nums[i+1];
        //     int x = 0, y = i+1;
        //     if(mi<nums[i]&&nums[i]<ma){
        //         return true;
        //     }
        //     while(x<i){
        //         mi = mi<nums[x]?mi:nums[x];
        //         ++x;
        //     }
        //     if(mi<nums[i]&&nums[i]<ma){
        //         return true;
        //     }
        //     while(y<len){
        //         ma = ma>nums[y]?ma:nums[y];
        //         ++y;
        //     }
        //     if(mi<nums[i]&&nums[i]<ma){
        //         return true;
        //     }
        // }
        // return false;
        int light = INT_MAX;
        int mid = INT_MAX;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]<=light){
                light = nums[i];
            }else if(nums[i]<=mid){
                mid = nums[i];
            }else{
                return true;
            }
        }
        return false;
    }
};
