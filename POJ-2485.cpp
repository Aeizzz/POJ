#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 550;
int mp[maxn][maxn];
struct Node{
    int u,v;
    int cost;
}node[maxn*maxn];
bool cmd(Node a,Node b){
    return a.cost<b.cost;
}
int fa[maxn];
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
void union1(int x,int y){
    int r1=find(x);
    int r2=find(y);
    if(r1!=r2) fa[r1]=r2;
}
bool same(int x,int y){
    return find(x)==find(y);
}
void init(){
    for(int i=0;i<maxn;i++) fa[i]=i;
}
int main(){
    int t;scanf("%d",&t);
    while(t--){
        init();
        int n;scanf("%d",&n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&mp[i][j]);
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                node[cnt].u=i;
                node[cnt].v=j;
                node[cnt++].cost=mp[i][j];
            }
        }
        int sum=0;
        int pig=0;
        sort(node,node+cnt,cmd);
        for(int i=0;i<cnt;i++){
            int u=node[i].u;
            int v=node[i].v;
            if(!same(u,v)){
                union1(u,v);
                sum++;
                if(sum==n-1)
                    pig=node[i].cost;

            }
        }
        printf("%d\n",pig);
    }
    return 0;
}
