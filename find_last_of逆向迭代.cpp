class Solution {
public:
    int firstUniqChar(string s) {
        // for(auto i : s){
        //     if(count(s.begin(),s.end(),i)==1){
        //         return s.find(i);
        //     }
        // }
        // return -1;
        for(int i=0;i<s.size();i++){
            if(s.find(s[i])==s.find_last_of(s[i])){
                return i;
            }
        }
        return -1;
    }
};
