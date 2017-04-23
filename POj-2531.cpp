#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 50;
int A[maxn],B[maxn];
int mp[maxn][maxn];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&mp[i][j]);
        }
    }
    int ans=-1;
    int cnt1,cnt2;
    for(int i=1;i<(1<<n);i++){
        cnt1=cnt2=0;
        for(int j=0;j<n;j++){
            if(i&(1<<j)) A[cnt1++]=j;
            else B[cnt2++]=j;
        }
        int sum=0;
        for(int k=0;k<cnt1;k++){
            for(int j=0;j<cnt2;j++){
                sum+=mp[A[k]][B[j]];
            }
        }
        ans=max(sum,ans);
    }
    printf("%d\n",ans);





    return 0;
}
