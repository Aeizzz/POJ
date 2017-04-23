#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
using namespace std;
const int maxn = 1010;
struct node{
    int u,v;
    string name;
}road[maxn];
bool app[30],use[maxn];
int ind[30],oud[30],anc[30],s[maxn];
int n,S,stop,t;
bool cmd(const node &a,const node &b){
    return a.name<b.name;
}
int get_father(int x){
    return anc[x]==x?x:anc[x]=get_father(anc[x]);
}
int change(char ch){
    return (ch-'a')+1;
}
bool exist_euler_circuit(){
    int t=0;
    for(int i=1;i<=26;i++)
        if(app[i]){
            if(t==0) t=get_father(i);
            if(get_father(i)!=t) return 0;
        }
    int sum=0;
    S=0;
    for(int i=1;i<=26;i++)
        if(app[i]){
            if(ind[i]!=oud[i]){
                if(abs(ind[i]-oud[i])>1) return 0;
                sum++;
                if(oud[i]>ind[i]) S=i;
            }
        }
    if(sum==0){
        for(int i=1;i<=26;i++){
            if(app[i]){
                S=i;
                break;
            }
        }
    }
    return 1;
}
void dfs(int now){
    for(int i=1;i<=n;i++){
        if(!use[i] && road[i].u==now){
            use[i]=1;
            dfs(road[i].v);
            s[++stop]=i;
        }
    }
}
void init(){
    cin>>n;
    memset(ind,0,sizeof(ind));
    memset(oud,0,sizeof(oud));
    memset(anc,0,sizeof(anc));
    for(int i=0;i<30;i++) anc[i]=i;
    memset(app,0,sizeof(app));
    for(int i=1;i<=n;i++){
        cin>>road[i].name;
        road[i].u=change(road[i].name[0]);
        road[i].v=change(road[i].name[road[i].name.size()-1]);
        app[road[i].u]=app[road[i].v]=1;
        int u=get_father(road[i].u);
        int v=get_father(road[i].v);
        if(u!=v) anc[u]=v;
        oud[road[i].u]++;
        ind[road[i].v]++;
    }
}
void solve(){
    sort(road+1,road+1+n,cmd);
    if(!exist_euler_circuit()){
        cout<<"***"<<endl;
        return ;
    }
    stop=0;
    memset(use,0,sizeof(use));
    dfs(S);
    for(int i=stop;i>=2;i--){
        cout<<road[s[i]].name<<'.';
    }
    cout<<road[s[1]].name<<endl;

}
int main(){
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        init();
        solve();
    }
    return 0;
}
