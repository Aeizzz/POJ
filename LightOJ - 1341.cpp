#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
const int maxn = 1000005;
ll prime[maxn]={1,1,0};
ll pri[maxn];
ll c=0;
void init(){
    for(int i=2;i<maxn;i++){
        if(!prime[i]){
            pri[c++]=i;
            for(int j=i*2;j<maxn;j+=i){
                prime[j]=1;
            }
        }
    }
}
int main(){
    int t;scanf("%d",&t);
    int Case=1;
    init();
    while(t--){
        ll ans=1;
        ll a,b;scanf("%lld%lld",&a,&b);
        printf("Case %d: ",Case++);
        if(b>sqrt(a)){
            printf("%d\n",0);
            continue;
        }
        ll x=a;
        for(int i=0;i<c&& pri[i]*pri[i]<=x;i++){
            int cc=0;
            while(x%pri[i]==0){
                cc++;
                x/=pri[i];
            }
            ans*=cc+1;
        }
        if(x>1) ans*=2;
        ans/=2;
        for(int i=1;i<b;i++){
            if(a%i==0) ans--;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
