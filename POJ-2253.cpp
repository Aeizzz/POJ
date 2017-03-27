/*
青蛙要从一个石头跳到另一个石头上，要求跳的路线中最大跳（即某条路线中最远的那一步）的最小值，起始位置在第一个点，目的位置在第二个点，中间点在紧接着的输入
*/


#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn = 200+10;
int c;
int n;
const int inf = 9999999999;
double dis[maxn];
struct Point{
    int x,y;
}point[maxn];
double mp[maxn][maxn];
int book[maxn];
double disp(Point a,Point b){
    return (double)(sqrt(double(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)));
}
void dij(){
    for(int i=1;i<=n;i++){
        dis[i]=mp[1][i];
        book[i]=0;
    }
    book[1]=1;
    int u;
    int Min;
    for(int i=1;i<=n-1;i++){
        Min=inf;
        for(int j=1;j<=n;j++){
            if(book[j]==0 && dis[j]<Min){
                Min=dis[j];
                u=j;
            }
        }
        book[u]=1;
        for(int v=1;v<=n;v++){
            if(book[v]==0 && dis[v]>max(dis[u],mp[u][v]))
                dis[v]=max(dis[u],mp[u][v]);
        }
    }

}
int main(){
    int t=1;
    while(scanf("%d",&n)!=EOF && n){
        for(int i=1;i<=n;i++){
            int x,y;scanf("%d%d",&x,&y);
            point[i].x=x;
            point[i].y=y;
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                mp[i][j]=disp(point[i],point[j]);
                mp[j][i]=disp(point[i],point[j]);
            }
        }
        dij();
        double Max=0;
        for(int i=1;i<=n;i++){
            Max=max(dis[i],Max);
        }
        printf("Scenario #%d\n",t++);
        printf("Frog Distance = %.3f\n\n",dis[2]);
    }
    return 0;
}
