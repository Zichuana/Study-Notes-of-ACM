### auto pair

```c++
#include<iostream>
#include<cstdio>
#include<vector>
#include<utility>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int x;
        cin>>x;
        vector<int> v(x);
        vector<pair<int,int>> res;
        for(auto &i:v) {cin>>i;}
        int flag=-1;
        for(int i=1;i<x;i++){
            if(v[i]!=v[0]){
                flag=i;
                res.push_back({1,i+1});
            }
        }
        if(flag==-1){cout<<"NO"<<endl;continue;}
        for(int i=1;i<x;i++){
            if(v[i]==v[0]){
                res.push_back({flag+1,i+1});
            }
        }
        cout<<"YES"<<endl;
        for(auto i:res){cout<<i.first<<" "<<i.second<<endl;}
    }
    return 0;
}
```

