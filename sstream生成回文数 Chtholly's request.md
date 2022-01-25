### sstream生成回文数 Chtholly's request

```c++
#include<iostream>
#include<cstdio>
#include<sstream>
#include<algorithm>
#include<string>
using namespace std;
int main(){
    int k,p;
    cin>>k>>p;
    long long ans=0;
    for(int i=1;i<=k;i++){
        stringstream ss;
        ss<<i;
        string s=ss.str(),t=ss.str();
        reverse(t.begin(),t.end());
        stringstream sss;
        sss<<s+t;
        long long n;
        sss>>n;
        ans=(ans+n)%p;
    }
    cout<<ans<<endl;
    return 0;
}
```

