#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 15000;
int dp[30][maxn];
int a[30],w[30];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=m;i++) scanf("%d",&w[i]);
    memset(dp,0,sizeof(dp));
    dp[0][7500]=1;
    for(int i=1;i<=m;i++){
        for(int j=0;j<=15000;j++){
            if(dp[i-1][j]){
                for(int k=1;k<=n;k++){
                    dp[i][j+w[i]*a[k]]+=dp[i-1][j];
                }
            }
        }
    }
    printf("%d\n",dp[m][7500]);




    return 0;
}
