#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 1000000+10;
typedef long long ll;
ll a[maxn];
ll is_prime[maxn]={1,1,0};
void init(){
    for(int i=2;i<maxn;i++){
        if(!is_prime[i]){
            for(int j=i*2;j<maxn;j+=i){
                is_prime[j]=1;
            }
        }
    }
}
int main(){
    int t;scanf("%d",&t);
    init();
    int Case=1;
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%lld",&a[i]);
        }
        ll sum=0;
        for(int i=0;i<n;i++){
            for(int j=a[i]+1;;j++){
                if(is_prime[j]==0){
                    sum+=j;
                    break;
                }
            }
        }
        printf("Case %d: %lld Xukha\n",Case++,sum);

    }





    return 0;
}
