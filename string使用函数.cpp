class Solution {
public:
    bool isPalindrome(string s) {
        string ss="";
        for(int i=0;i<s.size();i++){
            if(isalnum(s[i])){
                ss+=s[i];
            }
        }
        transform(ss.begin(), ss.end(), ss.begin(), ::tolower);
        //toupper 转大写
	//islower(char c) 是否为小写字母
	//isupper(char c) 是否为大写字母
	//isdigit(char c) 是否为数字
	//isalpha(char c) 是否为字母
	//isalnum(char c) 是否为字母或者数字
	//toupper(char c) 字母小转大
	//tolower(char c) 字母大转小
	string sss(ss);
        reverse(ss.begin(),ss.end());
        if(ss == sss)
            return true;
        return false;
    }
};
