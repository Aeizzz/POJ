#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int maxn = 250;
//邻接矩阵
int tab[maxn][maxn];
//距源点距离，分层图
int dis[maxn];
queue<int> q;
int N,M,ANS;
int bfs(){
    int i,j;
    memset(dis,-1,sizeof(dis));
    dis[1]=0;
    while(!q.empty()) q.pop();
    q.push(1);
    while(!q.empty()){
        j=q.front();
        q.pop();
        for(i=1;i<=N;i++){
            if(dis[i]<0 && tab[j][i]>0){
                dis[i]=dis[j]+1;
                q.push(i);
            }
        }
    }
    if(dis[N]>0)
        return 1;
    else
        return 0;//汇点的DIS小于0，表明bfd不到汇点

}
int find(int x,int low){
    int i,a=0;
    if(x==N) return low;
    for(i=1;i<=N;i++){
        if(tab[x][i]>0 && dis[i]==dis[x]+1 && (a=find(i,min(low,tab[x][i])))){
            tab[x][i]-=a;
            tab[i][x]+=a;
            return a;
        }
    }
    return 0;
}
int main(){
    while(scanf("%d%d",&M,&N)!=EOF){
        memset(tab,0,sizeof(tab));
        for(int i=1;i<=M;i++){
            int f,t,flow;
            scanf("%d%d%d",&f,&t,&flow);
            tab[f][t]+=flow;
        }
        ANS=0;
        int tans;
        while(bfs()){

            while(tans=find(1,0x7fffffff))ANS+=tans;
        }
        printf("%d\n",ANS);
    }
    return 0;
}
