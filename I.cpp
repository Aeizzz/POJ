#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 10000+10;
int a[maxn];
int x[20],y[20];
int fun(int a,int b){
    int len1=0,len2=0;
    while(a){
        x[len1++]=a%2;
        a/=2;
    }

    while(b){
        y[len2++]=b%2;
        b/=2;
    }
    int i=0;
    int sum=0;
    while(i<len1 && i<len2){
        if(x[i]!=y[i]) sum++;
        i++;
    }
    while(i<len1){
        if(x[i]==1) sum++;
        i++;
    }
    while(i<len2){
        if(y[i]==1) sum++;
        i++;
    }
    return sum;
}
int main(){
   // printf("%d\n",12&5);
    int t;scanf("%d",&t);
    while(t--){
        int n;scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        int Max=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                Max=max(fun(a[i],a[j]),Max);
            }
        }
        printf("%d\n",Max);





    }




    return 0;
}
