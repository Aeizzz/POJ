#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int chese[10][10];
const int maxn = 65536+10;
int ans=33;
int zx[maxn],zy[maxn],ansx[maxn],ansy[maxn];
void read(){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            char ch;
            cin>>ch;
            if(ch=='-') chese[i][j]=0;
            else chese[i][j]=1;
        }
    }
}
bool comp(){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(chese[i][j]!=0) return false;
        }
    }
    return true;
}
void flip(int x,int y){
    for(int i=0;i<4;i++){
        chese[x][i]=!chese[x][i];
        chese[i][y]=!chese[i][y];
    }
    chese[x][y]=!chese[x][y];
}

void dfs(int x,int y,int t){
    if(comp()){
        if(ans>t){
            ans=t;
            for(int i=0;i<ans;i++){
                ansx[i]=zx[i];
                ansy[i]=zy[i];
            }
        }
        return ;
    }
    if(x>=4 || y>=4) return ;
    int nx,ny;
    nx=(x+1)%4;
    ny=y+(x+1)/4;

    dfs(nx,ny,t);
    flip(x,y);

    zx[t]=x+1;
    zy[t]=y+1;


    dfs(nx,ny,t+1);
    flip(x,y);

}
int main(){
    read();
//    for(int i=0;i<4;i++){
//        for(int j=0;j<4;j++){
//            printf("%d",chese[i][j]);
//        }
//        printf("\n");
//    }
    dfs(0,0,0);

    printf("%d\n",ans);

    for(int i=0;i<ans;i++){
        printf("%d %d\n",ansx[i],ansy[i]);
       // printf("%d %d\n",zx[i],zy[i]);
    }
    return 0;
}
