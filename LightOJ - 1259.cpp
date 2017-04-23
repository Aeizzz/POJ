#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 1e7+5;
int is_prime[maxn]={1,1,0};
int prime[maxn];
int x;
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
int main(){
    int t;scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int sum=0;
        for(int i=0;i<x;i++){
                if(is_prime[n-prime[i]]==0 && prime[i]<=n-prime[i]){
                    sum++;
                }
                if(prime[i]>n-prime[i]) break;
        }
        printf("%d\n",sum);
    }






    return 0;
}
