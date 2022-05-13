#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
int Map[505][505];
int dir[4][2]={{1,0},{-1,0},{0,-1},{0,1}};
int n,m,t,ans;
int sx,sy,fx,fy;
struct node{
    int x,y,step;
}now,nextt;
int BFS(int x,int y){
    queue<node> q;
    Map[x][y]=2;
    now.x=x;
    now.y=y;
    now.step=0;
    q.push(now);
    while(!q.empty()){
        int size = q.size();
        while(size--){
            now=q.front();
            q.pop();
            if(now.x==fx&&now.y==fy){
                // cout<<"OK2"<<endl;
                return now.step;
            }
            for(int i=0;i<4;i++){
                int xx=now.x+dir[i][0];
                int yy=now.y+dir[i][1];
                // cout<<"OK"<<endl;
                if(xx>0&&xx<=n&&yy>0&&yy<=m&&Map[xx][yy]!=1&&Map[xx][yy]!=2){
                // cout<<"OK1"<<endl;
                    nextt.x=xx;
                    nextt.y=yy;
                    nextt.step=now.step+1;
                    // cout<<nextt.step<<endl;
                    Map[xx][yy]=2;
                    q.push(nextt);
                }
            }
        }
    }
    return -1;
}
int main(){
    cin>>n>>m>>t;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            Map[i][j]=0;
        }
    }
    cin>>sx>>sy>>fx>>fy;
    Map[fx][fy]=3;
    while(t--){
        int x,y;
        cin>>x>>y;
        Map[x][y]=1;
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         cout<<Map[i][j];
    //     }
    //     cout<<endl;
    // }
    ans = BFS(sx,sy);
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         cout<<Map[i][j];
    //     }
    //     cout<<endl;
    // }
    cout<<ans<<endl;
    return 0;
}