class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // int i = 0,j;
        // for(; i<nums.size()-1; i++){
        //     int t = target-nums[i];
        //     for(j = i+1; j<nums.size(); j++){
        //         if(t==nums[j]){
        //             return{i,j};
        //         }
        //     }
        // }
        // return {i , j};
        map<int,int> mp;
        for(int i = 0; i<nums.size();i++){
            if(mp.count(target-nums[i])!=0){
                return {mp[target-nums[i]], i};
            }
            else{
                mp.insert(pair<int, int>(nums[i], i));
            }
        }
        return{};
    }
};
