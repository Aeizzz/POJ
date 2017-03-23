#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 50000+10;
int fa[maxn];
void init(int n){
    for(int i=0;i<=n;i++) fa[i]=i;
}
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
void union1(int x,int y){
    int r1=find(x),r2=find(y);
    if(r1!=r2) fa[r1]=r2;
}
int main(){
    int n,m;
    int t=1;
    while(~scanf("%d%d",&n,&m)){
        if(n==0&&m==0) break;
        init(n);
        for(int i=0;i<m;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            union1(a,b);
        }
        int sum=0;
        for(int i=1;i<=n;i++){
            if(fa[i]==i) sum++;
        }
        printf("Case %d: %d\n",t++,sum);
    }






    return 0;
}
