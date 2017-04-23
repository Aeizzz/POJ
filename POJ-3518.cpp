#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 1299709+10;
int is_prime[maxn];
int p[maxn];
void init(){
    for(int i=2;i<maxn;i++){
        if(!is_prime[i]){
            for(int j=i*2;j<maxn;j+=i)
            is_prime[j]=1;
        }
    }
    for(int i=2;i<maxn;i++){
        if(is_prime[i]){
            int j=i;
            while(is_prime[j]==1 && j<maxn) j++;
            j--;
            for(int k=i;k<=j;k++){
                p[k]=j-i+2;
            }
            i=j;
        }else p[i]=0;
    }
}
int main(){
    init();
    int n;
    while(scanf("%d",&n)&&n){
        printf("%d\n",p[n]);
    }







    return 0;
}
