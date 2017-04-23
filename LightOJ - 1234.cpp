#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 1e8+1000;
double x[maxn/50+10];
void init(){
    x[0]=0;
    x[1]=1.0;
    double t=1.0;
    for(int i=2;i<maxn;i++){
        t+=1.0/i;
        if(i%50==0) x[i/50]=t;
    }
}
int main(){
    int t;
    scanf("%d",&t);
    init();
    int Cae=1;
    while(t--){
        int n;
        scanf("%d",&n);
        int t=n/50;
        double ans=x[t];
        for(int i=t*50+1;i<=n;i++){
            ans+=1.0/i;
        }
        printf("Case %d: %.10lf\n",Cae++,ans);

    }






    return 0;
}
