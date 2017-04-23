#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
ll exgcd(ll a,ll b,ll & x,ll & y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    ll r = exgcd(b, a%b, x, y);
    ll t = y;
    y = x - (a/b)*y;
    x = t;
    return r;
}

int main(){
    ll x,y,m,n,l;
    while(~scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&l)){
        ll i,k,r;
        ll a=n<m?m-n:n-m;
        ll b=n<m?y-x:x-y;
        b=(b+l)%l;
        r=exgcd(a,l,x,y);
        if(b%r!=0){
            printf("Impossible\n");
        }else{
            ll xx=(x*(b/r))%(l/r);
            if(xx<0) xx+=(l/r);
            printf("%lld\n",xx);
        }
    }
    return 0;
}
