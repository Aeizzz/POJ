#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 1000000+100;
const int M = 1000000000;
int dp[maxn];
int main(){
    int n;
    scanf("%d",&n);
    dp[0]=dp[1]=1;
    for(int i=2;i<=n;i++){
        if(i&1){
            dp[i]=dp[i-1];
        }else{
            dp[i]=(dp[i-2]+dp[i/2])%M;
        }
    }
    printf("%d\n",dp[n]);
    return 0;
}
