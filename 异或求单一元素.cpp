class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // int res;
        // for(auto i : nums){
        //     if(count(nums.begin(),nums.end(),i) == 1){
        //         res = i;
        //         break;
        //     }
        // }
        int res = 0;
        for(auto i:nums){
            res = i^res;
        }
        return res;
    }
};
