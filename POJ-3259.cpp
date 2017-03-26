#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn = 510;
const int inf = 9999999;
struct Node{
    int u,v;
    int t;
}E[2500*2+200+10];
int d[maxn];
int c;
int n,m,w;
bool flod(){
    for(int i=1;i<maxn;i++) d[i]=inf;
    d[1]=0;
    for(int i=1;i<n;i++){
            bool flag = false;

        for(int j=0;j<c;j++){
            int u=E[j].u;
            int v=E[j].v;
            int t=E[j].t;
            if(d[v]>d[u]+t){
                d[v]=d[u]+t;
                flag = true;
            }
        }
        if(!flag) return false;
    }
    for(int i=0;i<c;i++){
        if(d[E[i].v]>d[E[i].u]+E[i].t) return true;
    }
    return false;
}



int main(){
    int f;
    scanf("%d",&f);
    while(f--){

        scanf("%d%d%d",&n,&m,&w);
        c=0;
        for(int i=0;i<m;i++){
            int u,v,t;
            scanf("%d%d%d",&u,&v,&t);
            E[c].u=u;
            E[c].v=v;
            E[c].t=t;
            c++;
            E[c].u=v;
            E[c].v=u;
            E[c].t=t;
            c++;
        }
        for(int i=0;i<w;i++){
            int u,v,t;
            scanf("%d%d%d",&u,&v,&t);
            E[c].u=u;
            E[c].v=v;
            E[c].t=-t;
            c++;
        }
        if(flod()){
            printf("YES\n");
        }
        else printf("NO\n");
    }
    return 0;
}
