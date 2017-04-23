#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
int main(){
    int t;scanf("%d",&t);
    int Case=1;
    while(t--){
        ll n;scanf("%lld",&n);
        int m=sqrt(n);
        ll ret=0;
        for(int i=1;i<=m;i++){
            ret+=n/i;
        }
        for(int i=1;i<=m;i++){
            ret+=(n/i-n/(i+1))*i;
        }
        if(m==n/m) ret-=m;
        printf("Case %d: %lld\n",Case++,ret);

    }
    return 0;
}
