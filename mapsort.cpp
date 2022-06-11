class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        for(auto i:nums){
            mp[i]++;
        }
        vector< pair<int,int> > v (mp.begin(),mp.end());
        sort(v.begin(),v.end(),cmp);
        nums.clear();
        for(vector< pair<int,int> >::iterator it = v.begin();it!=v.end();it++){
            if(k==0){
                break;
            }
            nums.push_back(it->first);
            k--;
        }
        return nums;
    }
    static bool cmp(pair<int,int> &a , pair<int,int> &b)
    {
	    return a.second>b.second;
    }
};
