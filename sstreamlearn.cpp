#include<sstream>
#include<string>
#include<iostream>
using namespace std;
int main(){
    string s="hello world and wzh is pig!";//简单划分出单词
    stringstream sstream(s);
    while(sstream){
        string ss;
        sstream>>ss;
        cout << ss << endl;
    }

    stringstream stream;//int to string 
    string s2;
    int i=10086;
    stream<<i;
    stream>>s2;
    cout<<s2+"k"<<endl;

    stream.clear();

    char r[10];//同理int to char
    stream<<10086;
    stream>>r;
    cout<<r<<endl;

    string s3=to_string(10086);//利用std::to_string
    cout<<s3<<endl;

    return 0;
}