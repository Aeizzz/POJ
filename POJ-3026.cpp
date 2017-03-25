#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<iostream>
#include<queue>
using namespace std;
const int maxn = 110;
//地图
char mp[maxn][maxn];
int fa[maxn];
//两个点之间的距离；
int cost[maxn][maxn];
//存在点的坐标
int a[maxn][maxn];
//距离
int T[maxn][maxn];
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int w,h;
//点的个数
int tot;
//存图
struct Node{
    int x;int y;
    Node(int x,int y):x(x),y(y){}
};
struct node{
    int u,v;
    int cost;
}node[maxn*maxn];
bool cmd(struct node a,struct node b){
    return a.cost<b.cost;
}
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
void union1(int x,int y){
    int r1=find(x);
    int r2=find(y);
    if(r1!=r2){
        fa[r1]=r2;
    }
}
void bfs(int x,int y){
    queue<Node> q;
    memset(T,-1,sizeof(T));
    q.push(Node(x,y));
    T[x][y]=0;
    while(!q.empty()){
        Node now = q.front();
        q.pop();
        if(a[now.x][now.y]!=-1){
            cost[a[x][y]][a[now.x][now.y]]=T[now.x][now.y];
        }

        for(int i=0;i<4;i++){
            int nx=now.x+dir[i][0];
            int ny=now.y+dir[i][1];
            if(T[nx][ny]!=-1 || mp[nx][ny]=='#') continue;
                T[nx][ny]=T[now.x][now.y]+1;
                q.push(Node(nx,ny));

        }
    }
}

int krs(int n){
    int t=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(cost[i][j]>0){
                node[t].u=i;
                node[t].v=j;
                node[t++].cost=cost[i][j];
            }
        }
    }
    sort(node,node+t,cmd);
    int sum=0;
    for(int i=0;i<t;i++){
        int u=node[i].u;
        int v=node[i].v;
        if(find(u)!=find(v)){
            union1(u,v);
            sum+=node[i].cost;
        }
    }
    return sum;
}

void init(){
    memset(a,-1,sizeof(a));
    for(int i=0;i<maxn;i++) fa[i]=i;
    memset(cost,0,sizeof(cost));
    memset(T,-1,sizeof(T));
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        init();
        tot=0;
        scanf("%d%d",&w,&h);
        gets(mp[0]);
        for(int i=0;i<h;i++){
            gets(mp[i]);
            for(int j=0;j<w;j++){
                if(mp[i][j]=='A' || mp[i][j]=='S'){
                    a[i][j]=tot++;
                }
            }
        }
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(a[i][j]!=-1){
                    bfs(i,j);
                }
            }
        }
        int ans=krs(tot);
        printf("%d\n",ans);

    }
    return 0;
}
