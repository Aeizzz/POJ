#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int chese[4][4];
int ans=33;
void read(){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            char ch;
            cin>>ch;
            if(ch=='b')chese[i][j]=1;
            else chese[i][j]=0;
        }
    }
}
bool comp(){
    int sum=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            sum+=chese[i][j];
        }
    }
    if(sum%16==0) return true;
    else return false;
}
void fan(int x,int y){
    if(x>=0 && x<4 && y>=0 && y<4)
        chese[x][y]=!chese[x][y];
}
void filp(int s){
    int x=s/4;
    int y=s%4;
    fan(x,y);
    fan(x-1,y);
    fan(x+1,y);
    fan(x,y+1);
    fan(x,y-1);
}

void dfs(int s,int d){
    if(comp()){
        ans=min(ans,d);
        return ;
    }
    if(s>=16) return ;
    dfs(s+1,d);
    filp(s);
    dfs(s+1,d+1);
    filp(s);
}
int main(){
    read();
    dfs(0,0);
    if(ans>=33)printf("Impossible\n");
    else printf("%d\n",ans);
    return 0;
}
