#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn = 1000+10;
struct Node{
    double l,r;
}node[maxn];
bool cmd(Node a,Node b){
    return a.l<b.l;
}

int main(){
    int t=1;
    int n,d;
    while(~scanf("%d%d",&n,&d)){
        if(n==0 && d==0) break;
        int flag=0;
        for(int i=0;i<n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            double tmp=sqrt((double)(d*d)-y*y);
            node[i].l=x-tmp;
            node[i].r=x+tmp;
            if(y>d) flag=1;
        }
        sort(node,node+n,cmd);
        printf("Case %d: ",t++);
        if(flag){
            printf("-1\n");
            continue;
        }
        Node line = node[0];
        int sum=1;
        for(int i=1;i<n;i++){
            if(line.r<node[i].l){
                sum++;
                line=node[i];
            }else if(line.r>=node[i].r){
                line=node[i];
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
