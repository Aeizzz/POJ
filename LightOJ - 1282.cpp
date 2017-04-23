#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
ll qpow(ll a,int b){
    ll ans=1;
    while(b){
        if(b&1) ans=(ans*a)%1000;
        a=(a*a)%1000;
        b>>=1;
    }
    return ans;
}
int main(){
    int t;
    int Case=1;
    scanf("%d",&t);
    while(t--){
        int a;
        int b;
        scanf("%d%d",&a,&b);
        ll p=qpow(a,b);
        double ans=1.0*b*log10(a*1.0);
        ans=ans-(ll)ans;
        printf("Case %d: %lld %03lld\n",Case++,(ll)(pow(10,ans)*100),p);

    }
    return 0;
}
