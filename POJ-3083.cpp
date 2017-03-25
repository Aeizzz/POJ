#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
#include<string>
#include<iostream>
using namespace std;
const int maxn = 50;
char mp[maxn][maxn];
bool vis[maxn][maxn];
int step[maxn][maxn];
int start_x,start_y,end_x,end_y;
int w,h;
int Right[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
int Left[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
struct Node{
    int x,y;
    Node(int x,int y):x(x),y(y){}
};
int dfs(int x,int y,int t,const int dir[][2]){
        if(x==end_x && y==end_y){
            return 1;
        }
        int step=0;
        for(int i=0;i<4;i++){
            int T=(t+i+3)%4;
            int nx=x+dir[T][0];
            int ny=y+dir[T][1];
            if(nx>=0 && nx<h && ny>=0 && ny<w && (mp[nx][ny]=='.'||mp[nx][ny]=='E')){
                return step=dfs(nx,ny,T,dir)+1;
            }
        }
        return step;
}
int bfs(int x,int y){
    queue<Node> q;
    q.push(Node(x,y));
    vis[x][y]=1;
    step[x][y]=1;
    while(!q.empty()){
        Node now = q.front();
        int zx=now.x;
        int zy=now.y;
        q.pop();
        for(int i=0;i<4;i++){
            int nx=zx+Left[i][0];
            int ny=zy+Left[i][1];
            if(nx>=0 && nx<h && ny>=0 && ny<w && (mp[nx][ny]=='.'||mp[nx][ny]=='E')&& vis[nx][ny]==0){
                q.push(Node(nx,ny));
                step[nx][ny]=step[zx][zy]+1;
                vis[nx][ny]=1;
                if(nx==end_x && ny==end_y){
                    return step[nx][ny];
                }
            }
        }
    }

}




int main(){
    int t;
    scanf("%d",&t);
    while(t--){
    	memset(vis,0,sizeof(vis));
		memset(step,0,sizeof(step));
        scanf("%d%d",&w,&h);
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin>>mp[i][j];
                if(mp[i][j]=='S'){
                    start_x=i;
                    start_y=j;
                }
                if(mp[i][j]=='E'){
                    end_x=i;
                    end_y=j;
                }
            }
        }
        int ansr=1;
        ansr=dfs(start_x,start_y,0,Right);
        int ansl=1;
        ansl=dfs(start_x,start_y,0,Left);
        int ans=bfs(start_x,start_y);
        printf("%d %d %d\n",ansl,ansr,ans);

    }

    return 0;
}
