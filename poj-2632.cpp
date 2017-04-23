#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
#define maxn 111
struct node
{
    int x,y,to;
}r[maxn];
int T,a,b,n,m,mark[maxn][maxn];
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int Action(int robot,char *action,int repeat)
{
    if(action[0]=='F')
    {
        while(repeat--)
        {
            mark[r[robot].x][r[robot].y]=0;
            int x=r[robot].x+dx[r[robot].to],y=r[robot].y+dy[r[robot].to];
            if(x<1||x>a||y<1||y>b)
            {
                printf("Robot %d crashes into the wall\n",robot);
                return 0;
            }
            if(mark[x][y])
            {
                printf("Robot %d crashes into robot %d\n",robot,mark[x][y]);
                return 0;
            }
            r[robot].x=x,r[robot].y=y;
            mark[x][y]=robot;
        }
    }
    else
    {
        if(action[0]=='L')r[robot].to=(r[robot].to+3*repeat)%4;
        else r[robot].to=(r[robot].to+repeat)%4;
    }
    return 1;
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        memset(mark,0,sizeof(mark));
        scanf("%d%d%d%d",&a,&b,&n,&m);
        for(int i=1;i<=n;i++)
        {
            char dir[3];
            scanf("%d%d%s",&r[i].x,&r[i].y,dir);
            if(dir[0]=='W')r[i].to=0;
            else if(dir[0]=='N')r[i].to=1;
            else if(dir[0]=='E')r[i].to=2;
            else r[i].to=3;
            mark[r[i].x][r[i].y]=i;
        }
        int flag=1;
        while(m--)
        {
            int robot,repeat;char action[3];
            scanf("%d%s%d",&robot,action,&repeat);
            if(flag)flag=Action(robot,action,repeat);
        }
        if(flag)printf("OK\n");
    }
    return 0;
}
