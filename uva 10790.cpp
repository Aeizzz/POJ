#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
ll fun(ll a,ll b){
    return a*(a-1)/2*b*(b-1)/2;
}
int main(){
    ll a,b;
    int t=1;
    while(scanf("%lld%lld",&a,&b)){
        if(a==0 && b==0 ) break;
        printf("Case %d: %lld\n",t++,fun(a,b));
    }
    return 0;
}
