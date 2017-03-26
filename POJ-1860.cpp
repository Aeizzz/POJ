#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 10000;
int n,m,s,t;
double V;
struct Node{
    int u,v;
    double r,c;
}node[maxn];
double dis[maxn];
bool fold(){
    memset(dis,0,sizeof(dis));
    dis[s]=V;
    for(int j=0;j<n-1;j++){
        bool flag=false;
        for(int i=0;i<t;i++){
            int u,v;
            u=node[i].u;v=node[i].v;
            double r=node[i].r,c=node[i].c;
            if(dis[v]<(dis[u]-c)*r){
                dis[v]=(dis[u]-c)*r;
                flag=true;
            }
        }
        if(!flag){
          break;
        }
    }
    for(int i=0;i<t;i++){
        if(dis[node[i].v]<(dis[node[i].u]-node[i].c)*node[i].r){
            return true;
        }
    }
    return false;

}
int main(){
    while(~scanf("%d%d%d%lf",&n,&m,&s,&V)){
        for(int i=0;i<m;i++){
        int u,v;
        double rab,cab,rba,cba;
        scanf("%d%d%lf%lf%lf%lf",&u,&v,&rab,&cab,&rba,&cba);
            node[t].u=u;
            node[t].v=v;
            node[t].r=rab;
            node[t++].c=cab;
            node[t].u=v;
            node[t].v=u;
            node[t].r=rba;
            node[t++].c=cba;
        }
        if(fold()) printf("YES\n");
        else printf("NO\n");
    }





    return 0;
}
