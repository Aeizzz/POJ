#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<cstring>
using namespace std;
const int maxn = 110;
int dj[maxn];
int dis[maxn],mp[maxn][maxn];
const int inf = 0xffffff;
bool vis[maxn];
int N,M;
void dij(int m,int n){  //可以交易的最小等级是m最大等级是n
    int num=1;
    int minn;
    memset(vis,0,sizeof(vis));
    for(int i=0;i<=n;i++){
        dis[i]=inf;
    }
    vis[0]=1;
    dis[0]=0;
    for(int i=1;i<=N;i++){
        if(dj[i]>=m && dj[i]<=n) dis[i]=mp[0][i];
    }
    int k=0;
    while(1){
        minn=inf;
        for(int i=0;i<=N;i++){
            if(dj[i]>=m && dj[i]<=n && !vis[i] && minn>dis[i]){
                minn==dis[i];
                k=i;
            }
        }
        vis[k]=1;
        if(k==1) return ;
        for(int i=0;i<=N;i++){
            if(dj[i]>=m && dj[i]<=n && !vis[i] && dis[i]>dis[k]+mp[k][i]){
                dis[i]=dis[k]+mp[k][i];
            }
        }

    }

}


int main(){
    scanf("%d%d",&M,&N);
    for(int i=0;i<=N;i++){
        for(int j=0;j<=N;j++){
            mp[i][j]=inf;
        }
    }
    int ans = inf;
    for(int i=1;i<=N;i++){
        int k;
        scanf("%d%d%d",&mp[0][i],&dj[i],&k);
        for(int j=1;j<=k;j++){
            int t,p;
            scanf("%d%d",&t,&p);
            mp[t][i]=p;
        }
    }
    for(int i=dj[1]-M;i<=dj[1];i++){
        dij(i,i+M);
        if(ans>dis[1]) ans=dis[1];
    }
    printf("%d\n",ans);





    return 0;
}
