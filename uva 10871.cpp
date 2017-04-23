#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 100010;
int prime[maxn];
int is_prime[maxn];
int x;
int sum[maxn];
void init(){
    x=0;
    for(int i=2;i<maxn;i++){
        if(!is_prime[i]){
            prime[x++]=i;
            for(int j=i*2;j<maxn;j+=i){
                is_prime[j]=1;
            }
        }
    }
}
bool pr(int y){
    if(y<100000) return is_prime[y]==0?true:false;
    for(int i=0;i<x;i++){
        if(y%prime[i]==0) return false;
    }
    return true;
}
int main(){
    init();int t;
    scanf("%d",&t);
    while(t--){
        int n;scanf("%d",&n);

        for(int i=1;i<=n;i++){
            int x;
            scanf("%d",&x);
            sum[i]=sum[i-1]+x;
        }
        bool ok=false;
        for(int i=2;i<maxn;i++){
            for(int j=1;j+i<=n;j++){
                int k=sum[j+i-1]-sum[j-1];
                if(pr(k)==true){
                    ok=true;
                    printf("Shortest primed subsequence is length %d:",i);
                    for(int k=1;k<=i;k++){
                        printf(" %d",sum[j+k-1]-sum[j+k-2]);
                    }
                    printf("\n");
                    break;
                }
            }
            if(ok)break;
        }
        if(!ok){
            printf("This sequence is anti-primed.\n");
        }
    }
    return 0;
}
