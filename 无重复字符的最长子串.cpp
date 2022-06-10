class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.size(), j = 0,res = 0;
        bool flag[255] = {false};
        for(int i = 0; i<len ; i++){
            while(flag[s[i]]){
                flag[s[j]]=false;
                j++;
            }
            flag[s[i]]=true;
            res = res>=(i-j+1)?res:(i-j+1);
            cout<<res<<endl;
        }
        return res;
    }
};
