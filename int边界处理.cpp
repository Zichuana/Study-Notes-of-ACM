class Solution {
public:
    int myAtoi(string s) {
        // string res = "";
        // int flag = 0;
        // for(int i = 0; i<s.size(); i++){
        //     if(isalnum(s[i])){
        //         res += s[i];
        //         if(res[i-1] == '-'){
        //             flag = 1;
        //         }
        //     }
        // }
        // int num = atoi(res);
        // if(flag){
        //     num = -num;
        // }
        // return num;
        int index = 0;
        int len = s.size();
        while (index < len && s[index] == ' '){
            index++;
        }
        if(index >= len){
            return 0;
        }
        int sign =  1;
        if(s[index] == '-' || s[index] == '+'){
            if(s[index] == '-'){
                sign = -1;
            }
            index++;
        }
        int res = 0;
        while (index < len){
            int num = s[index] - '0';
            // cout<<num<<endl;
            if(num > 9 || num < 0){
                break;
            }
            // if(((long long)res * 10 + (long long)num)/INT_MAX>0||-((long long)res * 10 + (long long)num)/INT_MIN>0){
            //     // cout<<"ok"<<endl;
            //     if(sign > 0){
            //         return INT_MAX;
            //         cout<<"ok1"<<endl;
            //     }else {
            //         return INT_MIN;
            //         cout<<"ok2"<<endl;
            //     }
            // }
            if(sign>0){
                if(((long long)res * 10 + (long long)num)/INT_MAX>0){
                    return INT_MAX;
                }
            }
            else{
                if(-((long long)res * 10 + (long long)num)/INT_MIN>0){
                    return INT_MIN;
                }
            }
            res = res * 10 + num;
            index++;
        }
        return res*sign;

    }
};
