#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
const int maxn = 100000*2;
queue<int> q;
bool vis[maxn];
int sum[maxn];
void bfs(int n,int k){
    q.push(n);
    vis[n]=1;
    sum[n]=0;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        if(x==k){
            printf("%d\n",sum[k]);
            break;
        }
        if(x-1>=0 && !vis[x-1]){
            q.push(x-1);
            vis[x-1]=1;
            sum[x-1]=sum[x]+1;
        }
        if(x<=k && !vis[x+1]){
            q.push(x+1);
            vis[x+1]=1;
            sum[x+1]=sum[x]+1;
        }
        if(x<=k && !vis[x*2]){
            q.push(x*2);
            vis[x*2]=1;
            sum[x*2]=sum[x]+1;
        }
    }
}

int main(){
    int n,k;

    while(~scanf("%d%d",&n,&k)){
        memset(sum,0,sizeof(sum));
        memset(vis,0,sizeof(vis));
        bfs(n,k);
    }




    return 0;
}
