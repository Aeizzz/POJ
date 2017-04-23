#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 150000+100;
int a[maxn];
int s[maxn],mod[maxn];
void print(int s,int t){
    printf("%d\n",t-s+1);
    for(int i=s;i<=t;i++){
        printf("%d\n",a[i]);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        s[i]=s[i-1]+a[i];
        if(s[i]%n==0){
            print(1,i);
            break;
        }else if(!mod[s[i]%n]){
            mod[s[i]%n]=i;
        }else{
            print(mod[s[i]%n]+1,i);
            break;
        }
    }
    return 0;
}
