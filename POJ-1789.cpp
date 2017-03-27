#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<map>
#include<iostream>
using namespace std;
map<string,int> mp;
const int maxn = 2000+10;
struct Node{
    int u,v;
    int cost;
}node[maxn*maxn];
string s[maxn];
int fa[maxn];
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
void union1(int x,int y){
    int r1=find(x),r2=find(y);
    if(r1!=r2) fa[r1]=r2;
}
int dis(string s1,string s2){
    int len=s1.size();
    int sum=0;
    for(int i=0;i<len;i++){
        if(s1[i]!=s2[i]) sum++;
    }
    return sum;
}
bool cmd(Node a,Node b){
    return a.cost<b.cost;
}

int main(){
    int n;
    while(~scanf("%d",&n) && n){
        for(int i=0;i<n;i++){
            string s1;
            cin>>s1;
            mp[s1]=i+1;
            s[i+1]=s1;
        }
        for(int i=0;i<maxn;i++) fa[i]=i;
        int c=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                node[c].u=i;
                node[c].v=j;
                node[c++].cost=dis(s[i],s[j]);
            }
        }
        sort(node,node+c,cmd);
        int sum=0;
        for(int i=0;i<c;i++){
            int u=node[i].u,v=node[i].v;
            if(find(u)!=find(v)){
                union1(u,v);
                sum+=node[i].cost;
            }
        }
        printf("The highest possible quality is 1/%d.\n",sum);
    }
    return 0;
}
