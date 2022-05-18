class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }
        // int len=s.size();
        // map<int,int> ms;
        // map<int,int> mt;
        // for(int i=0;i<len;i++){
        //     ms[s[i]]++;
        //     mt[t[i]]++;
        // }
        // for(auto i:ms){
        //     if(i.second!=mt[i.first])
        //         return false;
        // }
        // return true;
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        if(t.compare(s)!=0){
            return false;
        }
        return true;
    }
};
