#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
using namespace std;
const int maxn = 2000;
const int maxm = 50;
struct node{
    int s,t;
}r[maxn];
bool vis[maxn];
int deg[maxm],s[maxn];
int n,S,stop;
bool exist(){
    for(int i=1;i<=maxm-1;i++){
        if(deg[i]%2==1) return 0;
    }
    return 1;
}
void dfs(int now){
    for(int i=1;i<=n;i++){
        if(!vis[i] && (r[i].s == now || r[i].t==now)){
            vis[i]=1;
            dfs(r[i].s+r[i].t-now);
            s[++stop]=i;
        }
    }
}
int main(){
    int x,y,num;
    while(cin>>x>>y){
        if(x==0 && y==0) break;
        memset(deg,0,sizeof(deg));
        cin>>num;
        S=min(x,y);
        n=0;
        r[num].s=x;r[num].t=y;
        deg[x]++,deg[y]++;
        n=max(n,num);
        while(cin>>x>>y){
        if(x==0 && y==0) break;
            S=min(x,y);
            cin>>num;
            r[num].s=x;r[num].t=y;
            deg[x]++;deg[y]++;
            n=max(n,num);
        }
        if(exist()){
            stop=0;
            memset(vis,0,sizeof(vis));
            dfs(S);
            for(int i=stop;i>=2;i--) cout<<s[i]<<' ';
            cout<<s[1]<<endl;
        }else{
            cout<<"Round trip does not exist."<<endl;
        }
    }

    return 0;
}
