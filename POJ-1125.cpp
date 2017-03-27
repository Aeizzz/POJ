#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 100+10;
int mp[maxn][maxn];
const int inf = 999999;
void init(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) mp[i][j]=inf;
    }
}
int main(){
    int n;
    while(~scanf("%d",&n) && n){
        init(n);
        for(int i=1;i<=n;i++){
            int p;scanf("%d",&p);
            for(int j=1;j<=p;j++){
                int v,cost;
                scanf("%d%d",&v,&cost);
                mp[i][v]=cost;
            }
        }

        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
                }
            }
        }
        int p=1;
        int Max=inf;
        for(int i=1;i<=n;i++){
            int sum=0;
            for(int j=1;j<=n;j++){
                if(i!=j && sum<mp[i][j]) sum=mp[i][j];
            }
            if(sum<Max){
                Max=sum;
                p=i;
            }
        }
        printf("%d %d\n",p,Max);

    }





    return 0;
}
