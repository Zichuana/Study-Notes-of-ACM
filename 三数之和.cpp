class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //我的错误代码
        // int len = nums.size();
        // map<int, int> flag; 
        // map<int, int> mp;
        // vector<int> mid;
        // vector<vector<int>> res;
        // sort(nums.begin(),nums.end());
        // if(len<3){
        //     return {};
        // }
        // if(len==3){
        //     if(nums[0]+nums[2]+nums[1]==0){
        //         res.push_back({nums[0],nums[1],nums[2]});
        //         return res;
        //     }
        //     return {};
        // }
        // for(int i=0; i<len-2; i++){
        //     if(flag.find(nums[i])!=flag.end()){
        //         continue;
        //     }
        //     flag[nums[i]]=-1;
        //     int l=i+1, r=len-1;
        //     mp.clear();
        //     while(l<len-1&&l < r){
        //         if(mp.count(nums[l])!=0){
        //             l++;
        //             continue;
        //         }
        //         if(nums[l]+nums[r]==-nums[i]){
        //             res.push_back({nums[i],nums[l],nums[r]});
        //             mp[nums[l]]=-1;
        //             mp[nums[r]]=-1;
        //         }
        //         else{
        //             if(r-1==l){
        //                 l++;
        //                 r = len-1;
        //                 continue;
        //             }
        //             r--;
        //         }
        //     }
        // }
        // return res;
        if (nums.size() < 3)
            return {};
        sort(nums.begin(), nums.end());
        int target = 0;
        vector<vector<int>> result;
        int len = nums.size();
        for (int i = 0; i < len-2 && nums[i] <= 0; ++i) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            target = -nums[i];
            int j = i+1, k = len-1;
            while (j < k) {
                if (nums[j]+nums[k] > target) k--;
                else if (nums[j]+nums[k] < target) j++;
                else {
                    result.push_back({nums[i],nums[j],nums[k]});
                    ++j, --k;
                    while (j < k && nums[j] == nums[j-1]) j++;
                    while (j < k && nums[k] == nums[k+1]) k--;
                }
            }
        }
        return result;
    }
};
