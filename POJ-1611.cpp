#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 30000;
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

int main(){
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        if(n==0 && m==0) break;
        for(int i=0;i<n;i++) fa[i]=i;
        for(int i=0;i<m;i++){
            int p;scanf("%d",&p);
            int x;
            scanf("%d",&x);
            for(int j=1;j<p;j++){
                int xx;
                scanf("%d",&xx);
                union1(x,xx);
            }
        }
        int sum=0;
        for(int i=1;i<n;i++){
            if(same(0,i)) sum++;
        }
        printf("%d\n",++sum);
    }
    return 0;
}
