class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        auto cmp = [&](auto& a, auto& b) {
            return a[1] > b[1];
        };
        sort(boxTypes.begin(), boxTypes.end(), cmp);
        int sum=0,cot=0,len=boxTypes.size();
        for(int i=0; i<len; i++){
            if(cot>truckSize){
                while(cot>truckSize){
                    cot--;
                    sum-=boxTypes[i-1][1];
                }
                return sum;
            }
            sum+=boxTypes[i][0]*boxTypes[i][1];
            cot+=boxTypes[i][0];
            if(cot==truckSize) break;
        }
        if(cot>truckSize){
            while(cot>truckSize){
                cot--;
                sum-=boxTypes[len-1][1];
            }
            return sum;
        }
        return sum;
    }
};
