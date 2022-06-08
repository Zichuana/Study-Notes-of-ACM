//一个N×M的由非负整数构成的数字矩阵，你需要在其中取出若干个数字，使得取出的任意两个数字不相邻（若一个数字在另外一个数字相邻8个格子中的一个即认为这两个数字相邻），求取出数字和最大是多少。
# include<iostream>
# include<cstdio>
# include<cstring>
# include<cmath>
using namespace std;
int arr[10][10],res[10][10];
int n,m,put,ans;
int dir[8][2]={{1,0},{-1,0},{0,-1},{0,1},{1,1},{-1,-1},{1,-1},{-1,1}};
void DFS(int x,int y){
    if(y == m){
        DFS(x+1,0);
        return;
    } 
    if(x == n){
        put = max(put, ans);
        return;
    }
    DFS(x,y+1);
    if(!res[x][y]){
        ans += arr[x][y];
        for(int i = 0; i < 8; i++){
            int xx = dir[i][0]+x;
            int yy = dir[i][1]+y;
            if(xx<n&&xx>=0&&yy<m&&yy>=0){
                ++res[xx][yy];
            }
        }
        DFS(x,y+1);
        for(int i = 0; i < 8; i++){
            int xx = dir[i][0]+x;
            int yy = dir[i][1]+y;
            if(xx<n&&xx>=0&&yy<m&&yy>=0){
                --res[xx][yy];
            }
        }
        ans -= arr[x][y];
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        put = 0;
        memset(arr,0,sizeof(arr));
        memset(res,0,sizeof(res));
        cin>>n>>m;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin>>arr[i][j];
            }
        }
        DFS(0,0);
        cout<<put<<endl;
    }
    return 0;
}
