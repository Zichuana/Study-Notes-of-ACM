class Solution {
private:
    vector<vector<int>> res;
    vector<int> tmp;

public:
    void dfs(int i, int n, int k)
    {
        if (tmp.size() == k)
        {
            res.push_back(tmp);
            return;
        }
        else if (i <= n)
        {
            tmp.push_back(i);
            // cout<<i<<endl;
            dfs(i + 1, n, k);
            tmp.pop_back();
            // cout<<' '<<i<<endl;
            dfs(i + 1, n, k);
        }
    }
    vector<vector<int>> combine(int n, int k) {
        dfs(1, n, k);
        return res;
    }
};
class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmp;
    void dfs(int i ,vector<int>& nums){
    if(i == nums.size()){
        res.push_back(tmp);
        return;
    }
    tmp.push_back(nums[i]);
    dfs(i+1,nums);
    tmp.pop_back();
    dfs(i+1,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0, nums);
        return res;
    }
};
