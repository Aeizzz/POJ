#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn =100;
bool map[maxn][maxn];
const int inf =1e9;
int n;
char str[maxn];
int vis[maxn];
int ans;
void dfs(int x,int channels){
    if(channels > ans) return ;
    if(x>=n){
        if(ans>channels) ans=channels;
        return ;
    }
    int i,j;
    for(i=1;i<=channels;i++){
        for(j=0;j<x;j++){
            if(vis[j]==i && map[x][j]) break;
        }
        if(j==x){
            vis[x]==i;
            dfs(x+1,channels);
            vis[x]=0;
        }
    }
    vis[x]=channels+1;
    dfs(x+1,channels+1);
    vis[x]=0;
}
int main(){
    while(~scanf("%d",&n) && n){
        memset(map,0,sizeof(map));
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++){
            scanf("%s",str);
            int s=str[0]-'A';
            for(int j=2;str[j];j++){
                map[s][str[j]-'A']=map[str[j]-'A'][s]=true;
            }
        }
        ans=inf;
        vis[0]=1;
        dfs(1,1);
        printf("%d channel%s needed.\n",ans,ans==1?"":"s");
    }
    return 0;
}
