#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn = 20;
bool vis[maxn];
int x[maxn],y[maxn],ans[maxn],t[maxn];
double dis[maxn][maxn];
double Min;
int n,casenum;
int sqr(int x){
    return x*x;
}
void dfs(int sum,int now,double s){
    if(sum==n){
        if(s<Min){
            Min=s;
            for(int i=1;i<=n;i++) ans[i]=t[i];
        }
        return ;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            t[sum+1]=i;
            dfs(sum+1,i,s+dis[now][i]);
            vis[i]=0;
        }
    }
}
void init(){
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i];
    }
    memset(dis,0,sizeof(dis));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dis[i][j]=sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j]))+16;
        }
    }
}
void solve(){
    cout<<"**********************************************************"<<endl;
    cout<<"Network #"<<++casenum<<endl;
    Min=1e10;
    dfs(0,0,0.0);
    for(int i=1;i<n;i++){
        cout<<"Cable requirement to connect ("<<x[ans[i]]<<","<<y[ans[i]]<<") to ("<<x[ans[i+1]]<<","<<y[ans[i+1]]<<") is "<<dis[ans[i]][ans[i+1]]<<" feet."<<endl;
    }
    cout<<"Number of feet of cable required is "<<Min<<"."<<endl;

}
int main(){
    ios::sync_with_stdio(false);
    cout<<fixed;
    cout.precision(2);
    while(cin>>n,n>0){
        init();
        solve();
    }
    return 0;
}
