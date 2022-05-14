#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int main(){
    int x;
    while(cin>>x){
        vector<int> v;
        while(x--){
            int mid;
            cin>>mid;
            v.push_back(mid);
        }
        vector<int> res = {v.rbegin(),v.rend()};
        for(auto i:res) cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
