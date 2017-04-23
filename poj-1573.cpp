//
// Created by hong-ll on 2017/4/17.
//
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 20;
char mp[maxn][maxn];
bool vis[maxn][maxn];
int step[maxn][maxn];
int n,m,s;
void DFS(int x,int y,int stepp){
    if(x<0 || x>=n||y<0 || y>=m){
        printf("%d step(s) to exit\n",stepp);
        return ;
    }
    if(vis[x][y]){
        printf("%d step(s) before a loop of %d step(s)\n",step[x][y],stepp-step[x][y]);
        return ;
    }
    vis[x][y]=true;
    step[x][y]=stepp;
    int xx,yy;
    if(mp[x][y]=='S'){
        xx=x+1;
        yy=y;
    }
    else if(mp[x][y]=='N'){
        xx=x-1;
        yy=y;
    }else if(mp[x][y]=='W'){
        xx=x;
        yy=y-1;
    }else if(mp[x][y]=='E'){
        xx=x;
        yy=y+1;
    }
    DFS(xx,yy,stepp+1);
}
int main(){
    while(~scanf("%d%d%d",&n,&m,&s)){
        if(n==0 && m==0 && s==0) break;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>mp[i][j];
            }
        }
        memset(vis,false,sizeof(vis));
        DFS(0,s-1,0);
    }
    return 0;
}
