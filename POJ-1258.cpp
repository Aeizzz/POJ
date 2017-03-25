#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn = 500;
ll a[maxn][maxn];

struct Node{
    int u,v;
    ll cost;
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
void kru(int n){
    ll sum=0;
    for(int i=0;i<n;i++){
        int u=node[i].u;
        int v=node[i].v;
        if(find(u)!=find(v)){
            union1(u,v);
            sum+=node[i].cost;
        }
    }
    printf("%lld\n",sum);

}
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%lld",&a[i][j]);
            }
        }
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                node[c].u=i;
                node[c].v=j;
                node[c++].cost=a[i][j];
            }
        }
        for(int i=0;i<maxn;i++) fa[i]=i;
        sort(node,node+c,cmd);
        kru(c);
    }

    return 0;
}
