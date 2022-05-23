class Solution {
public:
    map<int,int> res;
    int len;
    Solution(int n, vector<int>& blacklist) {
        // set<int> st;
        // for(int i = 0; i<n; i++){
        //     st.insert(i);
        // }
        // for(auto black:blacklist){
        //     st.erase(black);
        // }
        // int cot = 0;
        // for(auto x:st){
        //     res.insert(pair<int,int>(cot++,x));
        // }
        set<int> st;
        len = n-blacklist.size();
        for(int i = len; i<n; i++){
            st.insert(i);
        }
        for(auto black:blacklist){
            st.erase(black);
        }
        // for(auto i:st){
        //     cout<<i<<' ';
        // }
        // cout<<endl;
        auto j = st.begin();
        for(auto black:blacklist ){
            if(black<len){
                // cout<<*j<<endl;
                // cout<<' '<<black<<endl;
                res[black] = *j++;
            }
        }
    }
    
    int pick() {
        int mid  = rand()%len;
        // cout<<mid<<endl;
        return res.count(mid)?res[mid]:mid;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */
